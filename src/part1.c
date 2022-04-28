
/*
    @task       Solution of an IVS team project - creating calculator
    @team       "ludia bez týmu sem >>>"
    @members    Kramár Viktor, Chovanec David, Vilimovský Dan
    @created    26.4.2022
*/
/**
    @file   part1.c
    @author Viktor Kramár
    @brief  Combine mathematic library with .glade GUI 
*/



#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include "count.h"
#include "count.c"

// Make values global
GtkWidget 		*view;
GtkWidget 		*view2;
GtkWidget		*window;
GtkWidget		*pop;
GtkWidget		*fixed;
GtkWidget		*button1;
GtkWidget		*button2;
GtkWidget		*button3;
GtkWidget		*button4;
GtkWidget		*button5;
GtkWidget		*button6;
GtkWidget		*button7;
GtkWidget		*button8;
GtkWidget		*button9;
GtkWidget		*button10;
GtkWidget		*button11;
GtkWidget		*button12;
GtkWidget		*button13;
GtkWidget		*button14;
GtkWidget		*button15;
GtkWidget		*button16;
GtkWidget		*button17;
GtkWidget		*button18;
GtkWidget		*button19;
GtkWidget		*button20;
GtkWidget		*button21;
GtkWidget		*button22;
GtkWidget		*button23;
GtkBuilder		*builder; 
GtkTextMark 	*mark;
GtkTextBuffer 	*textbuf;
GtkTextBuffer 	*buffer;
GtkTextBuffer 	*buffer2;
GtkTextIter 	start, end;
GtkTextIter 	iter;


// Help Popup window Opening and Closing 
gboolean on_widget_deleted(GtkWidget *widget, GdkEvent *event, gpointer data)
{
	gtk_widget_hide(pop);
    return TRUE;
}

//Decide which function to call 
void find_operation(char* str_1)
{
	char * num1 ="0";
	char * num2 ="0";
	char * num3 ="0";

	num1 = strtok(str_1, " "); //find 1st number
	num2 = strtok(NULL, " ");  //find operand
	num3 = strtok(NULL, " ");  //find 2nd number

 	char buf[1000];	
 	float f1=0;
 	float f2=0;
 	int special=0;
 	int operand;

	if(num1 !=NULL && num2 !=NULL && num3 !=NULL  )
	{
 		f1 = atof(num1);
 		f2 = atof(num3);
	}

	else if(num1 !=NULL && num2 !=NULL && num3 ==NULL  )
	{
		f1 = atof(num1);
		f2 = atof(num2);
	}

	else{}

	if (num1 && num2 && num3 && *num3 != '\0') {

		if(strstr(num2, "+") != NULL) // if operand is + add the two numbers
		{
    		float number=addition(f1,f2);
  			const gint len = g_snprintf(buf, sizeof buf, "%f", number);
			gtk_text_buffer_set_text(buffer, buf, len);
		}

		if(strstr(num2, "-") != NULL) // if operand is - subtract the two numbers
		{
			float number=subtraction(f1,f2);
			const gint len = g_snprintf(buf, sizeof buf, "%f", number);
			gtk_text_buffer_set_text(buffer, buf, len);
		}

		if(strstr(num2, "*") != NULL) // if operand is * multiply the two numbers
		{
			float number=multiplication(f1,f2);
			const gint len = g_snprintf(buf, sizeof buf, "%f", number);
			gtk_text_buffer_set_text(buffer, buf, len);
		}

		if(strstr(num2, "/") != NULL) // if operand is / divide the two numbers
		{
			if( f2 == 0)
			{
				gtk_text_buffer_set_text(buffer, "MATH ERROR", -1);
			}

			else
			{
				float number=division(f1,f2);
				const gint len = g_snprintf(buf, sizeof buf, "%f", number);
				gtk_text_buffer_set_text(buffer, buf, len); 
			}
		}

		if(strstr(num2, "^") != NULL) // if operand is ^ power the two numbers
		{
			special=f2;
			if( special < 0)
			{
				gtk_text_buffer_set_text(buffer, "MATH ERROR", -1);
			}
			else
			{
				float number=power(f1,special);
				const gint len = g_snprintf(buf, sizeof buf, "%f", number);
				gtk_text_buffer_set_text(buffer, buf, len);
			}
		}

		if(strstr(num2, "√") != NULL) // if operand is √ root the two numbers
		{
			special=f2;
			if( f2 < 0 || f1 < 0)
			{
				gtk_text_buffer_set_text(buffer, "MATH ERROR", -1);
			}
			else
			{
				float number=root(f1,special);
				const gint len = g_snprintf(buf, sizeof buf, "%f", number);
				gtk_text_buffer_set_text(buffer, buf, len);
			}
		}
	}

	if (num1 && num2 && *num2 != '\0')  // if only operand and one number is read
	{

		if(strstr(num2, "!") != NULL) // if operand is ! use factorial on the number
		{
			if(f1 < 0)
			{
				gtk_text_buffer_set_text(buffer, "MATH ERROR", -1);
			}
			else
			{
			float number=double_factorial(f1);
			const gint len = g_snprintf(buf, sizeof buf, "%f", number);
			gtk_text_buffer_set_text(buffer, buf, len);
			}
		}

 		if(strstr(num1, "Sin") != NULL) // if operand is Sin use Sin function on the number
		{
			float number=our_sinus(f2);
			const gint len = g_snprintf(buf, sizeof buf, "%f", number);
			gtk_text_buffer_set_text(buffer, buf, len);

		}
	}
}


  





int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk

//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
 
	builder = gtk_builder_new_from_file ("Calc.glade");
 
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	pop = GTK_WIDGET(gtk_builder_get_object(builder, "pop"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(G_OBJECT(pop), "delete-event", G_CALLBACK(on_widget_deleted), NULL);


        gtk_builder_connect_signals(builder, NULL); //builder build the GUI from .glade file

	fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));
	button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
	button2 = GTK_WIDGET(gtk_builder_get_object(builder, "button2"));
	button3 = GTK_WIDGET(gtk_builder_get_object(builder, "button3"));
	button4 = GTK_WIDGET(gtk_builder_get_object(builder, "button4"));
	button5 = GTK_WIDGET(gtk_builder_get_object(builder, "button5"));
	button6 = GTK_WIDGET(gtk_builder_get_object(builder, "button6"));
	button7 = GTK_WIDGET(gtk_builder_get_object(builder, "button7"));
	button8 = GTK_WIDGET(gtk_builder_get_object(builder, "button8"));
	button9 = GTK_WIDGET(gtk_builder_get_object(builder, "button9"));
	button10 = GTK_WIDGET(gtk_builder_get_object(builder, "button10"));
	button11 = GTK_WIDGET(gtk_builder_get_object(builder, "button11"));
	button12 = GTK_WIDGET(gtk_builder_get_object(builder, "button12"));
	button13 = GTK_WIDGET(gtk_builder_get_object(builder, "button13"));
	button14 = GTK_WIDGET(gtk_builder_get_object(builder, "button14"));
	button15 = GTK_WIDGET(gtk_builder_get_object(builder, "button15"));
	button16 = GTK_WIDGET(gtk_builder_get_object(builder, "button16"));
	button17 = GTK_WIDGET(gtk_builder_get_object(builder, "button17"));
	button18 = GTK_WIDGET(gtk_builder_get_object(builder, "button18"));
	button19 = GTK_WIDGET(gtk_builder_get_object(builder, "button19"));
	button20 = GTK_WIDGET(gtk_builder_get_object(builder, "button20"));
	button21 = GTK_WIDGET(gtk_builder_get_object(builder, "button21"));
	button22 = GTK_WIDGET(gtk_builder_get_object(builder, "button22"));
	button23 = GTK_WIDGET(gtk_builder_get_object(builder, "button23"));
	view = GTK_WIDGET(gtk_builder_get_object(builder, "view"));
	view2 = GTK_WIDGET(gtk_builder_get_object(builder, "view2"));

	 buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
	 buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view2));
	 gtk_text_buffer_get_end_iter(buffer, &iter);
	
	//initialize window
	gtk_widget_show(window);
	gtk_widget_set_size_request(pop, 800, 700);

	gtk_main();
	return EXIT_SUCCESS;
	}
	


	//Decide what to do when certain button is clicked

	void on_button1_clicked (GtkButton *b, gpointer data) // number 0 button
	{
		gtk_text_buffer_insert_at_cursor(buffer, "0", -1);
	}

	void on_button2_clicked (GtkButton *b, gpointer data) // , button  
	{
		gtk_text_buffer_insert_at_cursor(buffer, ".", -1);
	}

	void on_button3_clicked (GtkButton *b, gpointer data) // Clear button
	{
		gtk_text_buffer_set_text(buffer,"", -1);
	}

	void on_button4_clicked (GtkButton *b, gpointer data) // = button
	{
		GtkTextIter start, end;
		gchar *text;
		gtk_text_buffer_get_bounds(buffer, &start, &end);
   		 text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
		find_operation(text);
	}


	void on_button5_clicked (GtkButton *b, gpointer data) // plus button
	{
		GtkTextIter start, end;
		gchar *text;
		gtk_text_buffer_get_bounds(buffer, &start, &end);
    	text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
		find_operation(text);	
		gtk_text_buffer_insert_at_cursor(buffer, " + ", -1);
	}

	void on_button6_clicked (GtkButton *b, gpointer data) // number 1 button
	{
		gtk_text_buffer_insert_at_cursor(buffer, "1", -1);
	}

	void on_button7_clicked (GtkButton *b, gpointer data) // number 2 button
	{
		gtk_text_buffer_insert_at_cursor(buffer, "2", -1);
	}

	void on_button8_clicked (GtkButton *b, gpointer data) // number 3 button
	{
		gtk_text_buffer_insert_at_cursor(buffer, "3", -1);
	}

	void on_button9_clicked (GtkButton *b, gpointer data) // factorial button
	{
		gtk_text_buffer_insert_at_cursor(buffer, " ! " ,-1);
	}

	void on_button10_clicked (GtkButton *b, gpointer data) // minus button
	{
		GtkTextIter start, end;
		gchar *text;
		gtk_text_buffer_get_bounds(buffer, &start, &end);
    	text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
		find_operation(text);	
		gtk_text_buffer_insert_at_cursor(buffer, " - ", -1);
	}

	void on_button11_clicked (GtkButton *b, gpointer data) // number 4 button
	{
		gtk_text_buffer_insert_at_cursor(buffer, "4", -1);
	}

	void on_button12_clicked (GtkButton *b, gpointer data) // number 5 button
	{
		gtk_text_buffer_insert_at_cursor(buffer, "5", -1);
	}

	void on_button13_clicked (GtkButton *b, gpointer data) // number 6 button
	{
		gtk_text_buffer_insert_at_cursor(buffer, "6", -1);
	}

	void on_button14_clicked (GtkButton *b, gpointer data) // power button
	 {
		GtkTextIter start, end;
		gchar *text;
		gtk_text_buffer_get_bounds(buffer, &start, &end);
    	text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
		find_operation(text);	
		gtk_text_buffer_insert_at_cursor(buffer, " ^ ", -1);
	}

	void on_button15_clicked (GtkButton *b, gpointer data) // multiplication button
	{
		GtkTextIter start, end;
		gchar *text;
		gtk_text_buffer_get_bounds(buffer, &start, &end);
    	text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
		find_operation(text);	
		gtk_text_buffer_insert_at_cursor(buffer, " * ", -1);
	}

	void on_button16_clicked (GtkButton *b, gpointer data) // number 7 button
	{
		gtk_text_buffer_insert_at_cursor(buffer, "7", -1);
	}

	void on_button17_clicked (GtkButton *b, gpointer data) // number 8 button
	{
		gtk_text_buffer_insert_at_cursor(buffer, "8", -1);
	}

	void on_button18_clicked (GtkButton *b, gpointer data) // number 9 button
	{
		gtk_text_buffer_insert_at_cursor(buffer, "9", -1);
	}

	void on_button19_clicked (GtkButton *b, gpointer data) // root button
	{
		GtkTextIter start, end;
		gchar *text;
		gtk_text_buffer_get_bounds(buffer, &start, &end);
    	text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
		find_operation(text);	
		gtk_text_buffer_insert_at_cursor(buffer, " √ ", -1);
	}

	void on_button20_clicked (GtkButton *b, gpointer data) // division button
	{
		GtkTextIter start, end;
		gchar *text;
		gtk_text_buffer_get_bounds(buffer, &start, &end);
    	text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
		find_operation(text);	
		gtk_text_buffer_insert_at_cursor(buffer, " / ", -1);
	}

	void on_button21_clicked (GtkButton *b, gpointer data) //delete button
	{
		mark = gtk_text_buffer_get_insert(buffer);
  	  	gtk_text_buffer_get_iter_at_mark(buffer, &start, mark);
   	 	gtk_text_buffer_backspace(buffer, &start, True, True);
	}

	void on_button22_clicked (GtkButton *b, gpointer data) //Help button
	{
		gtk_widget_show(pop);
		gtk_text_buffer_set_text(buffer2, "The calculator is controlled with the mouse, with which you can press the corresponding buttons on the screen or click directly into the text field and use your keyboard\n\n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "Press C to delete the entire expression displayed on the screen\n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "To delete one character shown on the display, press DEL\n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "the calculator supports decimal numbers that are entered by a character,\n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "Available operations:\n\n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "- addition -> +\n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "- subtraction-> -\n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "- multiplication-> *\n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "- division-> /\n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "- Nth power-> ^ \n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "- Nth root-> √\n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "- Sinus-> Sin\n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "- Factorial-> !\n\n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "The application is minimized by clicking on the \"_\" character in the upper right corner\n", -1);
		gtk_text_buffer_insert_at_cursor(buffer2, "The application is shut down by clicking on the \"X\" character in the upper right corner\n", -1);
	} 

	void on_button23_clicked (GtkButton *b, gpointer data) //Sin button
	{
		gtk_text_buffer_insert_at_cursor(buffer, " Sin ", -1);
	}

  
  
