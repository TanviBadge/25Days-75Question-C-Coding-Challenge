#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

void addContact(struct Contact contacts[], int *count) {
    if (*count >= 100) {
        printf("Phonebook is full!\n");
        return;
    }
    
    printf("Enter Name: ");
    scanf(" %49[^\n]", contacts[*count].name);
    
    printf("Enter Phone: ");
    scanf("%14s", contacts[*count].phone);
    
    printf("Enter Email: ");
    scanf("%49s", contacts[*count].email);
    
    (*count)++;
    printf("Contact added successfully!\n");
}

void displayContacts(struct Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts found!\n");
        return;
    }
    
    printf("\n%-20s %-15s %-30s\n", "Name", "Phone", "Email");
    printf("--------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++)
	 {
        printf("%-20s %-15s %-30s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
    
    printf("\nTotal contacts: %d\n", count);
}

void searchContact(struct Contact contacts[], int count, char name[]) {
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("\nContact found!\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
            return;
        }
    }
    
    if (!found) {
        printf("Contact not found!\n");
    }
}

void deleteContact(struct Contact contacts[], int *count, char name[]) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Contact contacts[100];
    int count = 0;
    int choice;
    char name[50];
    
    printf("\n========== PHONEBOOK APPLICATION ==========\n");
    
    while (1) {
        printf("\n========================================\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
                
            case 2:
                displayContacts(contacts, count);
                break;
                
            case 3:
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                searchContact(contacts, count, name);
                break;
                
            case 4:
                printf("Enter name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                deleteContact(contacts, &count, name);
                break;
                
            case 5:
                printf("Exiting Phonebook. Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please enter 1-5.\n");
        }
    }
    
    return 0;
}
