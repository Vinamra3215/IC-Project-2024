#include <gtk/gtk.h>
#include <time.h>

static gboolean update_time_label(GtkLabel *label)
{
    char buffer[100];
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    strftime(buffer, sizeof(buffer), "Current Date and Time:\n%Y-%m-%d %H:%M:%S", local_time);
    gtk_label_set_text(label, buffer);

    return G_SOURCE_CONTINUE;
}

static void When_Button1_clicked(GtkButton *button, gpointer user_data)
{
    g_print("Opening Contacts...\n");

    int result = system("b24cm1019_b24cm1026_b24mt1043_b24cm1068_Contacts.exe");

    if (result == -1)
    {
        g_print("Failed to open Contacts.\n");
    }
    else
    {
        g_print("Contacts exited with code %d\n", result);
    }
}

static void When_Button2_clicked(GtkButton *button, gpointer user_data)
{
    g_print("Starting the Snake Game...\n");

    int result = system("b24cm1019_b24cm1026_b24mt1043_b24cm1068_snake_game.exe");

    if (result == -1)
    {
        g_print("Failed to start the snake game.\n");
    }
    else
    {
        g_print("Snake Game exited with code %d\n", result);
    }
}

static void When_Button3_clicked(GtkButton *button, gpointer user_data)
{
    g_print("Opening To-Do List...\n");

    int result = system("b24cm1019_b24cm1026_b24mt1043_b24cm1068_todo_list.exe");

    if (result == -1)
    {
        g_print("Failed to start the Todo List.\n");
    }
    else
    {
        g_print("Todo List exited with code %d\n", result);
    }
}

static void When_Button4_clicked(GtkButton *button, gpointer user_data)
{
    g_print("Opening Calculator...\n");

    int result = system("b24cm1019_b24cm1026_b24mt1043_b24cm1068_Calculator.exe");

    if (result == -1)
    {
        g_print("Failed to start the calculator.\n");
    }
    else
    {
        g_print("Calculator exited with code %d\n", result);
    }
}

int main(int argc, char *argv[])
{
    gtk_init();

    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Smartphone");
    gtk_window_set_default_size(GTK_WINDOW(window), 360, 640);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget *clock_label = gtk_label_new(NULL);
    gtk_box_append(GTK_BOX(box), clock_label);

    g_timeout_add_seconds(1, (GSourceFunc)update_time_label, clock_label);

    GtkWidget *spacer = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_vexpand(spacer, TRUE);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

    int spacing = 10;
    gtk_grid_set_row_spacing(GTK_GRID(grid), spacing);
    gtk_grid_set_column_spacing(GTK_GRID(grid), spacing);

    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);

    GtkWidget *button1 = gtk_button_new();
    GtkWidget *button2 = gtk_button_new();
    GtkWidget *button3 = gtk_button_new();
    GtkWidget *button4 = gtk_button_new();

    GtkWidget *image1 = gtk_image_new_from_file("b24cm1019_b24cm1026_b24mt1043_b24cm1068_icon_phone.png");
    GtkWidget *image2 = gtk_image_new_from_file("b24cm1019_b24cm1026_b24mt1043_b24cm1068_icon_snake.jpg");
    GtkWidget *image3 = gtk_image_new_from_file("b24cm1019_b24cm1026_b24mt1043_b24cm1068_icon_todo.jpg");
    GtkWidget *image4 = gtk_image_new_from_file("b24cm1019_b24cm1026_b24mt1043_b24cm1068_icon_calculator.jpg");

    gtk_button_set_child(GTK_BUTTON(button1), image1);
    gtk_button_set_child(GTK_BUTTON(button2), image2);
    gtk_button_set_child(GTK_BUTTON(button3), image3);
    gtk_button_set_child(GTK_BUTTON(button4), image4);

    int button_size = 80;
    gtk_widget_set_size_request(button1, button_size, button_size);
    gtk_widget_set_size_request(button2, button_size, button_size);
    gtk_widget_set_size_request(button3, button_size, button_size);
    gtk_widget_set_size_request(button4, button_size, button_size);

    gtk_grid_attach(GTK_GRID(grid), button1, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button2, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button3, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button4, 1, 1, 1, 1);

    gtk_box_append(GTK_BOX(box), spacer);
    gtk_box_append(GTK_BOX(box), grid);

    g_signal_connect(button1, "clicked", G_CALLBACK(When_Button1_clicked), NULL);
    g_signal_connect(button2, "clicked", G_CALLBACK(When_Button2_clicked), NULL);
    g_signal_connect(button3, "clicked", G_CALLBACK(When_Button3_clicked), NULL);
    g_signal_connect(button4, "clicked", G_CALLBACK(When_Button4_clicked), NULL);

    g_signal_connect(window, "close-request", G_CALLBACK(gtk_window_destroy), NULL);

    gtk_window_present(GTK_WINDOW(window));

    g_main_loop_run(g_main_loop_new(NULL, FALSE));

    return 0;
}
