
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>

// Make them global
GtkWidget 	*view;
GtkWidget	*window;
GtkWidget	*fixed;
GtkWidget	*button1;
GtkWidget	*button2;
GtkWidget	*button3;
GtkWidget	*button4;
GtkWidget	*button5;
GtkWidget	*button6;
GtkWidget	*button7;
GtkWidget	*button8;
GtkWidget	*button9;
GtkWidget	*button10;
GtkWidget	*button11;
GtkWidget	*button12;
GtkWidget	*button13;
GtkWidget	*button14;
GtkWidget	*button15;
GtkWidget	*button16;
GtkWidget	*button17;
GtkWidget	*button18;
GtkWidget	*button19;
GtkWidget	*button20;
GtkWidget	*button21;
GtkWidget	*button22;
GtkWidget	*button23;
GtkBuilder	*builder; 

GtkTextBuffer *buffer;
GtkTextIter start, end;
GtkTextIter iter;

int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk

//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
 
	builder = gtk_builder_new_from_file ("Calc.glade");
 
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);


        gtk_builder_connect_signals(builder, NULL);

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

	 buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
	 gtk_text_buffer_get_end_iter(buffer, &iter);

	gtk_widget_show(window);

	gtk_main();
	return EXIT_SUCCESS;
	}
	
	void on_button1_clicked (GtkButton *b, gpointer data) {
	   gtk_text_buffer_insert_at_cursor(buffer, "0", -1);}

	void on_button2_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, ",", -1);}

	void on_button3_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "", -1);}

	void on_button4_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "", -1);}

	void on_button5_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "+", -1);}

	void on_button6_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "1", -1);}

	void on_button7_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "2", -1);}

	void on_button8_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "3", -1);}

	void on_button9_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "!" ,-1);}

	void on_button10_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "-", -1);}

	void on_button11_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "4", -1);}

	void on_button12_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "5", -1);}

	void on_button13_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "6", -1);}

	void on_button14_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "^", -1);}

	void on_button15_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "*", -1);}

	void on_button16_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "7", -1);}

	void on_button17_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "8", -1);}

	void on_button18_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "9", -1);}

	void on_button19_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "√", -1);}

	void on_button20_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "÷", -1);}

	void on_button21_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "", -1);}

	void on_button22_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "HELP", -1);}

	void on_button23_clicked (GtkButton *b, gpointer data) {
	gtk_text_buffer_insert_at_cursor(buffer, "Sin", -1);}

