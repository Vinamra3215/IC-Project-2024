#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact
{
    char name[50];
    char phone[15];
    char email[50];
    struct Contact *next;
} Contact;

Contact *loadContacts(const char *fileName);
void saveContacts(Contact *head, const char *fileName);
void addContact(Contact **head, char *name, char *phone, char *email);
void deleteContact(Contact **head, char *name);
void showContacts(Contact *head);

int main()
{
    Contact *list = loadContacts("contacts.txt");
    int choice;
    char name[50], phone[15], email[50];

    while (1)
    {
        printf("\nContact Manager\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Show All Contacts\n");
        printf("4. Save and Exit\n");
        printf("Pick an option: ");
        scanf("%d", &choice);
        getchar(); // Handle newline

        if (choice == 1)
        {
            printf("Enter name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Enter phone: ");
            fgets(phone, sizeof(phone), stdin);
            phone[strcspn(phone, "\n")] = '\0';
            printf("Enter email: ");
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\n")] = '\0';
            addContact(&list, name, phone, email);
        }
        else if (choice == 2)
        {
            printf("Enter name to remove: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            deleteContact(&list, name);
        }
        else if (choice == 3)
        {
            showContacts(list);
        }
        else if (choice == 4)
        {
            saveContacts(list, "contacts.txt");
            printf("Contacts saved. Goodbye!\n");
            return 0;
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }
}

Contact *loadContacts(const char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (!file)
        return NULL;

    Contact *head = NULL, *last = NULL;
    while (!feof(file))
    {
        Contact *newContact = (Contact *)malloc(sizeof(Contact));
        if (fscanf(file, "%49[^,],%14[^,],%49[^\n]\n",
                   newContact->name, newContact->phone, newContact->email) != 3)
        {
            free(newContact);
            break;
        }
        newContact->next = NULL;

        if (!head)
            head = newContact;
        else
            last->next = newContact;
        last = newContact;
    }
    fclose(file);
    return head;
}

void saveContacts(Contact *head, const char *fileName)
{
    FILE *file = fopen(fileName, "w");
    while (head)
    {
        fprintf(file, "%s,%s,%s\n", head->name, head->phone, head->email);
        head = head->next;
    }
    fclose(file);
}

void addContact(Contact **head, char *name, char *phone, char *email)
{
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    strcpy(newContact->email, email);
    newContact->next = NULL;

    if (!*head)
    {
        *head = newContact;
    }
    else
    {
        Contact *temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = newContact;
    }
    printf("Contact added!\n");
}

void deleteContact(Contact **head, char *name)
{
    Contact *cur = *head, *prev = NULL;

    while (cur && strcmp(cur->name, name) != 0)
    {
        prev = cur;
        cur = cur->next;
    }

    if (!cur)
    {
        printf("Contact not found.\n");
        return;
    }

    if (prev)
        prev->next = cur->next;
    else
        *head = cur->next;

    free(cur);
    printf("Contact removed.\n");
}

void showContacts(Contact *head)
{
    if (!head)
    {
        printf("No contacts to show.\n");
        return;
    }

    printf("\nContacts:\n");
    while (head)
    {
        printf("Name: %s, Phone: %s, Email: %s\n", head->name, head->phone, head->email);
        head = head->next;
    }
}