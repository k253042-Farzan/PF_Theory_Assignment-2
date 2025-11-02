#include <stdio.h>

#define ROWS 5
#define COLS 5
#define POWER_BIT       0  
#define OVERLOAD_BIT    1  
#define MAINT_BIT       2  
void updateSectorStatus(int grid[ROWS][COLS], int row, int col, int bitPos, int value);
void querySectorStatus(int grid[ROWS][COLS], int row, int col);
void runSystemDiagnostic(int grid[ROWS][COLS]);

int main() {
    int grid[ROWS][COLS] = {0};  
    int choice;

    while (1) {
        printf("\n=== IESCO Power Grid Monitoring System ===\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int row, col, bitPos, value;
            printf("Enter Row (0-%d): ", ROWS - 1);
            scanf("%d", &row);
            printf("Enter Column (0-%d): ", COLS - 1);
            scanf("%d", &col);
            printf("Enter Bit Position (0=Power, 1=Overload, 2=Maintenance): ");
            scanf("%d", &bitPos);
            printf("Enter Value (1=Set, 0=Clear): ");
            scanf("%d", &value);

            updateSectorStatus(grid, row, col, bitPos, value);
        }

        else if (choice == 2) {
            int row, col;
            printf("Enter Row (0-%d): ", ROWS - 1);
            scanf("%d", &row);
            printf("Enter Column (0-%d): ", COLS - 1);
            scanf("%d", &col);

            querySectorStatus(grid, row, col);
        }

        else if (choice == 3) {
            runSystemDiagnostic(grid);
        }

        else if (choice == 4) {
            printf("Exiting system...\n");
            break;
        }

        else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void updateSectorStatus(int grid[ROWS][COLS], int row, int col, int bitPos, int value) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid coordinates!\n");
        return;
    }

    if (value == 1) {
        grid[row][col] |= (1 << bitPos);    
    } else {
        grid[row][col] &= ~(1 << bitPos);  
    }

    printf("Sector (%d, %d) updated successfully.\n", row, col);
}

void querySectorStatus(int grid[ROWS][COLS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid coordinates!\n");
        return;
    }

    int status = grid[row][col];
    printf("\n--- Sector (%d, %d) Status Report ---\n", row, col);
    printf("Power Status         : %s\n", (status & (1 << POWER_BIT)) ? "ON" : "OFF");
    printf("Overload Warning     : %s\n", (status & (1 << OVERLOAD_BIT)) ? "OVERLOADED" : "NORMAL");
    printf("Maintenance Required : %s\n", (status & (1 << MAINT_BIT)) ? "YES" : "NO");
    printf("Binary Representation: %03d\n", status);
}

void runSystemDiagnostic(int grid[ROWS][COLS]) {
    int overloadedCount = 0;
    int maintenanceCount = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] & (1 << OVERLOAD_BIT))
                overloadedCount++;
            if (grid[i][j] & (1 << MAINT_BIT))
                maintenanceCount++;
        }
    }
    printf("\n=== System Diagnostic Report ===\n");
    printf("Total Overloaded Sectors     : %d\n", overloadedCount);
    printf("Total Maintenance Required   : %d\n", maintenanceCount);
}


