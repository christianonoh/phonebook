#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

Contact contacts[MAX_CONTACTS];
int contact_count = 0;

void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    char name[50], phone[20], email[50];
    printf("Enter name: ");
    scanf(" %[^\n]", name);
    printf("Enter phone: ");
    scanf(" %[^\n]", phone);
    printf("Enter email: ");
    scanf(" %[^\n]", email);

    strncpy(contacts[contact_count].name, name, sizeof(contacts[contact_count].name));
    strncpy(contacts[contact_count].phone, phone, sizeof(contacts[contact_count].phone));
    strncpy(contacts[contact_count].email, email, sizeof(contacts[contact_count].email));
    contact_count++;

    printf("Contact added: %s\n", name);
}

void remove_contact() {
    char name[50];
    printf("Enter name to remove: ");
    scanf(" %[^\n]", name);

    int found = 0;
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < contact_count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contact_count--;
            found = 1;
            printf("Contact removed: %s\n", name);
            break;
        }
    }
    if (!found) {
        printf("Contact not found: %s\n", name);
    }
}

void search_contact() {
    char name[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < contact_count; i++) {
        if (strcasestr(contacts[i].name, name)) {
            printf("Found: %s | %s | %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            return;
        }
    }
    printf("No contact found for: %s\n", name);
}

void list_contacts() {
    if (contact_count == 0) {
        printf("No contacts.\n");
        return;
    }

    for (int i = 0; i < contact_count; i++) {
        printf("%d. %s | %s | %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    printf("Total contacts: %d (sizeof Contact = %lu bytes)\n",
           contact_count, sizeof(Contact));
}

void menu() {
    printf("\n=== Contact Manager ===\n");
    printf("1. Add Contact(%d/%d)\n",contact_count, MAX_CONTACTS);
    printf("2. Remove Contact\n");
    printf("3. Search Contact\n");
    printf("4. List All Contacts(%d)\n", contact_count);
    printf("5. Quit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        menu();
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                list_contacts();
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}
