#include <stdbool.h>
#include <stdlib.h> // Include stdlib.h for rand()

#define KEY_BASE 0xFF200050
#define LEDR_BASE 0xFF200000

volatile int *KEY_PTR = (int *)KEY_BASE;

void write_pixel(int x, int y, short colour) {
    volatile short *vga_addr = (volatile short *)(0x08000000 + (y << 10) + (x << 1));
    *vga_addr = colour;
}

void box_line(int x, int y, int color) {
    for (int i = x; i < x + 30; i++) {
        for (int j = y; j < y + 3; j++) {
            write_pixel(i, j, color);
        }
    }
}

bool read_push_button(int button_mask) {
    return (*KEY_PTR & button_mask) ? true : false;
}

void delay(int milliseconds) {
    // Adjust the delay loop for appropriate timing
    for (int i = 0; i < milliseconds; i++) {
        for (int j = 0; j < 10000; j++) {
            // Do nothing
        }
    }
}

void draw_circle(int cx, int cy, int r, short colour) {
    int x, y;
    for (y = cy - r; y <= cy + r; y++) {
        for (x = cx - r; x <= cx + r; x++) {
            if ((x - cx) * (x - cx) + (y - cy) * (y - cy) < r * r) {
                write_pixel(x, y, colour);
            }
        }
    }
}

void draw_block(int x, int y, int color) {
    for (int i = x; i < x + 40; i++) {
        for (int j = y; j < y + 40; j++) {
            write_pixel(i, j, color);
        }
    }
}

void get_block_coordinates(int x, int y, int *column, int *row) {
    // Calculate column and row numbers based on the coordinates
    *column = x / 40; // Calculate column number of the block
    *row = y / 40;    // Calculate row number of the block
}

void make_block_black(int column, int row) {
    int x = column * 40; // Calculate the x coordinate of the block
    int y = row * 40;    // Calculate the y coordinate of the block
    
    // Assuming write_pixel function is available
    for (int i = x; i < x + 40; i++) {
        for (int j = y; j < y + 40; j++) {
            write_pixel(i, j, 0); // Set the pixel color to black
        }
    }
}

void write_char(int x, int y, char c) {
  volatile char * character_buffer = (char *) (0x09000000 + (y<<7) + x);
  *character_buffer = c;
}

void clear_char() {
	for (int x = 0; x<80; x++){
		for (int y=0; y<60; y++){
  			volatile char * character_buffer = (char *) (0x09000000 + (y<<7) + x);
  			*character_buffer = '\0';
		}
	}
}


void start_game() {
    // Clear the screen
    clear_char();

    // Draw the layout

    // Second part: "Welcome to Brick Breaker"
    char welcome_text[] = "Welcome to Brick Breaker";
    int welcome_text_length = strlen(welcome_text);
    int welcome_text_start = (80 - welcome_text_length) / 2;
    for (int x = 0; x < welcome_text_length; x++) {
        write_char(welcome_text_start + x, 8, welcome_text[x]);
    }

    // Fourth part: " - By Amitesh Raj"
    char author_text[] = " - By Amitesh Raj";
    int author_text_length = strlen(author_text);
    int author_text_start = (80 - author_text_length) / 2;
    for (int x = 0; x < author_text_length; x++) {
        write_char(author_text_start + x, 16, author_text[x]);
    }

    // Fifth part: "PRESS 3 TO START"
    char start_text[] = "PRESS 3 TO START";
    int start_text_length = strlen(start_text);
    int start_text_start = (80 - start_text_length) / 2;

    bool visible = true; // Initial visibility of the text

    while (1) {
		
		 if (read_push_button(0x8)) {
            break; // Check if key 3 is pressed
            
    }
        if (visible) {
            // Display the text
            for (int x = 0; x < start_text_length; x++) {
                write_char(start_text_start + x, 24, start_text[x]);
            }
        } else {
            // Clear the text
            for (int x = 0; x < start_text_length; x++) {
                write_char(start_text_start + x, 24, ' ');
            }
        }

        // Toggle visibility
        visible = !visible;

        for ( int i =0 ; i<4000000; i++){
		}
    }
}

void info(){
    // Draw the layout

    // Second part: "Welcome to Brick Breaker"
    char welcome_text[] = "Welcome to Brick Breaker";
    int welcome_text_length = strlen(welcome_text);
    int welcome_text_start = (80 - welcome_text_length) / 2;
    for (int x = 0; x < welcome_text_length; x++) {
        write_char(welcome_text_start + x, 8, welcome_text[x]);
    }

    // Fourth part: " - By Amitesh Raj"
    char author_text[] = " - By Amitesh Raj";
    int author_text_length = strlen(author_text);
    int author_text_start = (80 - author_text_length) / 2;
    for (int x = 0; x < author_text_length; x++) {
        write_char(author_text_start + x, 16, author_text[x]);
    }
}


void game_over() {
    // Clear the screen
    clear_char();

    // Write "YOU LOSE"
    char lose_text[] = "YOU LOSE";
    int lose_text_length = strlen(lose_text);
    int lose_text_start = (80 - lose_text_length) / 2;
    for (int x = 0; x < lose_text_length; x++) {
        write_char(lose_text_start + x, 8, lose_text[x]);
    }

    // Write "GAME OVER!!!"
    char game_over_text[] = "GAME OVER!!!";
    int game_over_text_length = strlen(game_over_text);
    int game_over_text_start = (80 - game_over_text_length) / 2;
    for (int x = 0; x < game_over_text_length; x++) {
        write_char(game_over_text_start + x, 16, game_over_text[x]);
    }
}


#define HEX3_HEX0_BASE 0xFF200020
#define HEX5_HEX4_BASE 0xFF200030


char seg7[10] =	{0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 
						 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01100111};



void seven_score(int score){
  volatile int * HEX3_HEX0_ptr = (int *) HEX3_HEX0_BASE;
	volatile int * HEX5_HEX4_ptr = (int *) HEX5_HEX4_BASE;
	
	    *HEX5_HEX4_ptr = seg7[score/100000] << 8;
		*HEX5_HEX4_ptr |= seg7[(score/10000)%10];

		*HEX3_HEX0_ptr = seg7[(score/1000)%10] << 24;
		*HEX3_HEX0_ptr |= seg7[(score/100)%10] << 16;

		*HEX3_HEX0_ptr |= seg7[(score/10)%10] << 8;
		*HEX3_HEX0_ptr |= seg7[score%10];
}









int main() {
    // Initialize screen with black pixels

    int line_x = 240;
    int line_y = 237;
    short line_color = 0x07E0; // Green color

    int edge_capture;
    bool key1_pressed = false;
    bool key2_pressed = false;

    int ball_initial_x = 40;
    int ball_initial_y = 80;
    int ball_velocity_x = 1;
    int ball_velocity_y = 1;
    int ball_color = 0x07e0;
    int ball_line_length = 5;
    int screen_width = 320;
    int screen_height = 240;
	


    int x, y;
    for (x = 0; x < 320; x++) {
        for (y = 0; y < 240; y++) {
            write_pixel(x, y, 0); // Black color
        }
    }



        start_game();
    while(1){
        if (read_push_button(0x8)) {
            break; // Check if key 3 is pressed
            
    }
    }

    clear_char();

    for (x = 0; x < 320; x++) {
        for (y = 0; y < 240; y++) {
            write_pixel(x, y, 0); // Black color
        }
    }



    
    



    bool blocks[4][8] = {
    {true, true, true, true, true, true, false, true},
    {true, true, false, true, false, true, true, true},
    {true, true, true, true, true, true, false, true},
    {false, true, true, false, true, true, true, true}
};

    // Define a color for the rock
    #define ROCK_COLOR 0xA541 // Orange

    // Define the positions of the rocks
  
	

       short colors[] = {
    0xF800, // Red
    0x07E0, // Green
    0x001F, // Blue
    0xFFE0, // Yellow
    0xF81F, // Magenta
    0x07FF, // Cyan
    0xA541, // Orange
    0xBDF7, // Pink
    0xF000, // Dark Red
    0x07D0, // Light Green
    0x0010, // Dark Blue
    0xFD20, // Light Purple
    0xFFC0, // Peach
    0x8400, // Dark Green
    0xFC00, // Light Blue
    0xFEA0, // Light Orange
    0x8204, // Maroon
    0xC67D, // Light Brown
    0x8000, // Dark Yellow
    0x07C0, // Light Green
    0x8180, // Olive
    0xDAC0, // Light Yellow
    0x32C6, // Teal
    0x8400, // Dark Green
    0x01DF, // Sky Blue
    0xC618, // Copper
    0x03E0, // Lime
    0xD618, // Tan
    0x66C6, // Sage
    0x8204, // Maroon
    0xBDF6, // Light Pink
    0xFC40, // Violet
};
	
	int rock_positions[6][2] = {
        {0,120},
        {80, 40},
        {120,120},
        {160,40},
        {240, 0},
        {240, 80}
    };
    
	

        int k=0 ; 

     for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                if (blocks[i][j]) {
                    draw_block(j * 40, i * 40, colors[k]);
                    k=k+1;
                }
            }
        }
	
	for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                if (!blocks[i][j]) {
					
					for (int P = 0; P < 6; P++) {
	
  		 			draw_block(rock_positions[P][0], rock_positions[P][1], 0xffff);
				}
					
					
                    
                }
            }
        }
	
	for (int i = 0; i < 6; i++) {
	
   draw_block(rock_positions[i][0], rock_positions[i][1], 0xffff);
	}


    int lives =3 ; 


    c:
    // Initial position of the line
    line_x = 240;
    line_y = 237;
    line_color = 0x07E0; // Green color

    edge_capture;
     key1_pressed = false;
     key2_pressed = false;

    ball_initial_x = 40;
    ball_initial_y = 80;
    ball_velocity_x = 1;
    ball_velocity_y = 1;
    ball_color = 0x07e0;
    ball_line_length = 5;
    screen_width = 320;
    screen_height = 240;


    
	

       
    
    

    while (1) {
        box_line(line_x, line_y, line_color);

        seven_score(lives);

        edge_capture = *KEY_PTR & 0xF; // Read the 4 least significant bits

        // Check if Key 0 is pressed
        if ((edge_capture & 0x1) && !key1_pressed) {
            if (line_x > 0) {
                box_line(line_x, line_y, 0); // Clear previous line
                line_x -= 20; // Move line left
                box_line(line_x, line_y, line_color); // Draw new line
            }
            key1_pressed = true;
        } else if (!(edge_capture & 0x1)) {
            key1_pressed = false;
        }

        // Check if Key 1 is pressed
        if ((edge_capture & 0x2) && !key2_pressed) {
            if (line_x < 290) {
                box_line(line_x, line_y, 0); // Clear previous line
                line_x += 20; // Move line right
                box_line(line_x, line_y, line_color); // Draw new line
            }
            key2_pressed = true;
        } else if (!(edge_capture & 0x2)) {
            key2_pressed = false;
        }

        // Introduce a delay to control loop execution speed
        delay(200); // Adjust delay value as needed

        // Clear previous ball
        for (int i = 0; i < ball_line_length; i++) {
            write_pixel(ball_initial_x + i, ball_initial_y, 0);
        }

        // Move the ball
        ball_initial_x += ball_velocity_x;
        ball_initial_y += ball_velocity_y;

        if (ball_initial_y <= 237) {
            // Check for bounces
            if (ball_initial_x < 0 || ball_initial_x + ball_line_length >= screen_width) {
                ball_velocity_x = -ball_velocity_x; // Reverse horizontal direction
                ball_initial_x += ball_velocity_x; // Move back into bounds
            }
            if (ball_initial_y < 0 || ball_initial_y >= screen_height) {
                ball_velocity_y = -ball_velocity_y; // Reverse vertical direction
                ball_initial_y += ball_velocity_y; // Move back into bounds
            }
        }

        if (ball_initial_y > 237) {
            if (ball_initial_x >= line_x && ball_initial_x + ball_line_length <= line_x + 30) {
                // Ball collides with the line
                int random_direction = rand() % 3; // Generate a random number (0 or 1)
               
                ball_velocity_x = random_direction-(rand()%3); // Reverse horizontal direction
                ball_velocity_y = -ball_velocity_y; // Reverse vertical direction
                ball_initial_y += ball_velocity_y;
            }

            else if(ball_initial_x+5<line_x){

                ball_initial_y += ball_velocity_y;
                ball_initial_x += ball_velocity_x;


                lives=lives-1; 

                box_line(line_x,line_y,0);

                if ( lives >0){
                    goto c; 
                }

                if (lives==0){

                    seven_score(lives);

                    for ( int i =0 ; i<320 ; i++){
                        for ( int j=0 ; j<240 ; j++){
                            write_pixel(i,j,0);           
                        }
                    }

                    game_over();
                    break;


                }
            }

           


        }

        // Collision detection with rocks
        int column, row;
        get_block_coordinates(ball_initial_x, ball_initial_y, &column, &row);
        if (blocks[row][column]) {
            // Ball hits a block
            if (!(column * 40 == rock_positions[0][0] && row * 40 == rock_positions[0][1]) && 
                !(column * 40 == rock_positions[1][0] && row * 40 == rock_positions[1][1]) &&
                !(column * 40 == rock_positions[2][0] && row * 40 == rock_positions[2][1]) &&
                !(column * 40 == rock_positions[3][0] && row * 40 == rock_positions[3][1]) &&
                !(column * 40 == rock_positions[4][0] && row * 40 == rock_positions[4][1]) &&
                !(column * 40 == rock_positions[5][0] && row * 40 == rock_positions[5][1])) {


                int random_value = (rand() % 2 == 0) ? -1 : 1;
				
				ball_velocity_y=random_value; // Reverse vertical direction



				
				int random_value1 = (rand() % 2 == 0) ? -1 : 1;
                ball_velocity_x=random_value1;
                ball_initial_x += ball_velocity_x+(rand()%3)-1;


                make_block_black(column, row);      // Turn the block black
                blocks[row][column] = false;         // Mark the block as empty
            }
        }
		
		
		
            if ((column * 40 == rock_positions[0][0] && row * 40 == rock_positions[0][1]) ||
                (column * 40 == rock_positions[1][0] && row * 40 == rock_positions[1][1]) ||
                (column * 40 == rock_positions[2][0] && row * 40 == rock_positions[2][1]) ||
                (column * 40 == rock_positions[3][0] && row * 40 == rock_positions[3][1]) ||
                (column * 40 == rock_positions[4][0] && row * 40 == rock_positions[4][1]) ||
                (column * 40 == rock_positions[5][0] && row * 40 == rock_positions[5][1])) {
                 ball_velocity_x =-ball_velocity_x; // Reverse horizontal direction

                 ball_initial_x =ball_initial_x+ ball_velocity_x-(rand()%3);
                
				int random_value3 = (rand() % 2 == 0) ? -1 : 1;
				ball_velocity_y=random_value3;
                
                
                blocks[row][column] = false;        // Mark the block as empty
            }
        
		
		

        // Draw the new ball
        for (int i = 0; i < ball_line_length; i++) {
            write_pixel(ball_initial_x + i, ball_initial_y, ball_color);
        }

        // Delay for smoother animation
        for (int i = 0; i < 100000; i++) {
        }
    }

    return 0;
}

	