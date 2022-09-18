// Switchdraw

#include <draw.h>

#include <string.h>
#include <stdio.h>

#include <switch.h>

void draw(int n, int color) {
    switch (color) {
		case 0: 
		printf(BLACK);
		break;
		case 1: 
		printf(BLUE);
		break;
		case 2: 
		printf(CYAN);
		break;
		case 3: 
		printf(GREEN);
		break;
		case 4: 
		printf(MAGENTA);
		break;
		case 5: 
		printf(RED);
		break;
        case 6: 
		printf(WHITE);
		break;
        case 7: 
		printf(YELLOW);
		break;
        default:
        printf("Invalid color!");
        break;
	}

    for(int i = 0; i < n; i++) {
        printf(" ");
    }
}

int main(int argc, char **argv) {
    consoleInit(NULL);

    // Configure our supported input layout: a single player with standard controller styles
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
    PadState pad;
    padInitializeDefault(&pad);

    // Clear screen and home cursor
    printf(CONSOLE_ESC(2J));

    // Draw
    for(int i = 0; i < 4; i++) {
        for(int i = 0; i < 4; i++) {
            draw(2, 0); draw(2, 3); draw(4, 0); draw(2, 3); draw(4, 0);
        }
        draw(2, 0); draw(2, 3); draw(4, 0); draw(2, 3);
        printf("\n");

        for(int i = 0; i < 4; i++) {
            draw(1, 0); draw(1, 3); draw(2, 6); draw(1, 3); draw(2, 0); draw(1, 3); draw(2, 6); draw(1, 3); draw(3, 0);
        }
        draw(1, 0); draw(1, 3); draw(2, 6); draw(1, 3); draw(2, 0); draw(1, 3); draw(2, 6); draw(1, 3);

        printf("\n");
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 4; j++) {
                draw(1, 0); draw(1, 3); draw(1, 6); draw(1, 0); draw(1, 3); draw(2, 0); draw(1, 3); draw(1, 6); draw(1, 0); draw(1, 3); draw(3, 0);
            }
            draw(1, 0); draw(1, 3); draw(1, 6); draw(1, 0); draw(1, 3); draw(2, 0); draw(1, 3); draw(1, 6); draw(1, 0); draw(1, 3);
            printf("\n");
        }
        
        for(int i = 0; i < 4; i++) {
            draw(1, 0); draw(10, 3); draw(3, 0);
        }
        draw(1, 0); draw(10, 3);
        
        printf("\n");
        for(int i = 0; i < 4; i++) {
            draw(4, 3); draw(1, 0); draw(2, 3); draw(1, 0); draw(4, 3); draw(2, 0);
        }
        draw(4, 3); draw(1, 0); draw(2, 3); draw(1, 0); draw(4, 3);

        printf("\n");
        for(int i = 0; i < 4; i++) {
            draw(12, 3); draw(2, 0);
        }
        draw(12, 3);

        printf("\n");
        for(int i = 0; i < 4; i++) {
            draw(2, 3); draw(1, 0); draw(6, 3); draw(1, 0); draw(2, 3); draw(2, 0);
        }
        draw(2, 3); draw(1, 0); draw(6, 3); draw(1, 0); draw(2, 3);

        printf("\n");
        for(int i = 0; i < 4; i++) {
            draw(3, 3); draw(6, 0); draw(3, 3); draw(2, 0);
        }
        draw(3, 3); draw(6, 0); draw(3, 3);

        printf("\n");
        for(int i = 0; i < 4; i++) {
            draw(1, 0); draw(10, 3); draw(3, 0);
        }
        draw(1, 0); draw(10, 3);

        printf("\n\n");
    }

    // Main loop
    while(appletMainLoop()) {
        // Scan the gamepad. This should be done once for each frame
        padUpdate(&pad);

        // padGetButtonsDown returns the set of buttons that have been newly pressed in this frame compared to the previous one
        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_Plus) break; // break in order to return to hbmenu

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
