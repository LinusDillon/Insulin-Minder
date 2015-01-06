// 
//  Font data for Picopixel 5pt
// 
// Font information for Picopixel 5pt
// Character height: 1
// Start character: *
// End character: ° (degrees symbol)
// Width, in pixels, of space character: 2
// Thanks to: http://www.dafont.com/micropixel.font

#include <avr/pgmspace.h>

// Character bitmaps for Picopixel 5pt
prog_uchar Picopixel5[] = 
{
	// @0 '*' (3 pixels wide)
	0x28, //   # # 
	0x10, //    #  
	0x28, //   # # 

	// @3 '+' (3 pixels wide)
	0x10, //    #  
	0x38, //   ### 
	0x10, //    #  

	// @6 ',' (2 pixels wide)
	0x80, // #     
	0x40, //  #    

	// @8 '-' (3 pixels wide)
	0x10, //    #  
	0x10, //    #  
	0x10, //    #  

	// @11 '.' (1 pixels wide)
	0x40, //  #    

	// @12 '/' (3 pixels wide)
	0x60, //  ##   
	0x10, //    #  
	0x0C, //     ##

	// @15 '0' (3 pixels wide)
	0x38, //   ### 
	0x44, //  #   #
	0x38, //   ### 

	// @18 '1' (2 pixels wide)
	0x08, //     # 
	0x7C, //  #####

	// @20 '2' (3 pixels wide)
	0x64, //  ##  #
	0x54, //  # # #
	0x48, //  #  # 

	// @23 '3' (3 pixels wide)
	0x44, //  #   #
	0x54, //  # # #
	0x28, //   # # 

	// @26 '4' (3 pixels wide)
	0x1C, //    ###
	0x10, //    #  
	0x78, //  #### 

	// @29 '5' (3 pixels wide)
	0x5C, //  # ###
	0x54, //  # # #
	0x24, //   #  #

	// @32 '6' (3 pixels wide)
	0x38, //   ### 
	0x54, //  # # #
	0x20, //   #   

	// @35 '7' (3 pixels wide)
	0x64, //  ##  #
	0x14, //    # #
	0x0C, //     ##

	// @38 '8' (3 pixels wide)
	0x28, //   # # 
	0x54, //  # # #
	0x28, //   # # 

	// @41 '9' (3 pixels wide)
	0x08, //     # 
	0x54, //  # # #
	0x38, //   ### 

	// @44 ':' (1 pixels wide)
	0x28, //   # # 

	// @45 '<' (2 pixels wide)
	0x10, //    #  
	0x28, //   # # 

	// @47 '=' (3 pixels wide)
	0x28, //   # # 
	0x28, //   # # 
	0x28, //   # # 

	// @50 '>' (2 pixels wide)
	0x28, //   # # 
	0x10, //    #  

	// @52 '?' (3 pixels wide)
	0x04, //      #
	0x54, //  # # #
	0x08, //     # 

	// @55 'A' (3 pixels wide)
	0x78, //  #### 
	0x14, //    # #
	0x78, //  #### 

	// @58 'B' (3 pixels wide)
	0x7C, //  #####
	0x54, //  # # #
	0x28, //   # # 

	// @61 'C' (3 pixels wide)
	0x38, //   ### 
	0x44, //  #   #
	0x44, //  #   #

	// @64 'D' (3 pixels wide)
	0x7C, //  #####
	0x44, //  #   #
	0x38, //   ### 

	// @67 'E' (3 pixels wide)
	0x7C, //  #####
	0x54, //  # # #
	0x54, //  # # #

	// @70 'F' (3 pixels wide)
	0x7C, //  #####
	0x14, //    # #
	0x04, //      #

	// @73 'G' (3 pixels wide)
	0x38, //   ### 
	0x44, //  #   #
	0x34, //   ## #

	// @76 'H' (3 pixels wide)
	0x7C, //  #####
	0x10, //    #  
	0x7C, //  #####

	// @79 'I' (1 pixels wide)
	0x7C, //  #####

	// @80 'J' (3 pixels wide)
	0x20, //   #   
	0x40, //  #    
	0x3C, //   ####

	// @83 'K' (3 pixels wide)
	0x7C, //  #####
	0x18, //    ## 
	0x64, //  ##  #

	// @86 'L' (3 pixels wide)
	0x7C, //  #####
	0x40, //  #    
	0x40, //  #    

	// @89 'M' (5 pixels wide)
	0x7C, //  #####
	0x08, //     # 
	0x30, //   ##  
	0x08, //     # 
	0x7C, //  #####

	// @94 'N' (4 pixels wide)
	0x7C, //  #####
	0x08, //     # 
	0x10, //    #  
	0x7C, //  #####

	// @98 'O' (3 pixels wide)
	0x38, //   ### 
	0x44, //  #   #
	0x38, //   ### 

	// @101 'P' (3 pixels wide)
	0x7C, //  #####
	0x14, //    # #
	0x08, //     # 

	// @104 'Q' (3 pixels wide)
	0x38, //   ### 
	0x44, //  #   #
	0xB8, // # ### 

	// @107 'R' (3 pixels wide)
	0x7C, //  #####
	0x14, //    # #
	0x68, //  ## # 

	// @110 'S' (3 pixels wide)
	0x48, //  #  # 
	0x54, //  # # #
	0x24, //   #  #

	// @113 'T' (3 pixels wide)
	0x04, //      #
	0x7C, //  #####
	0x04, //      #

	// @116 'U' (3 pixels wide)
	0x3C, //   ####
	0x40, //  #    
	0x3C, //   ####

	// @119 'V' (3 pixels wide)
	0x1C, //    ###
	0x60, //  ##   
	0x1C, //    ###

	// @122 'W' (5 pixels wide)
	0x3C, //   ####
	0x40, //  #    
	0x30, //   ##  
	0x40, //  #    
	0x3C, //   ####

	// @127 'X' (3 pixels wide)
	0x6C, //  ## ##
	0x10, //    #  
	0x6C, //  ## ##

	// @130 'Y' (3 pixels wide)
	0x0C, //     ##
	0x70, //  ###  
	0x0C, //     ##

	// @133 'Z' (3 pixels wide)
	0x64, //  ##  #
	0x54, //  # # #
	0x4C, //  #  ##

	// @136 '°' (2 pixels wide)
	0x04, //      #
	0x0C, //     ##
};

prog_uchar Picopixel5_width[] PROGMEM = 
{
  	3, 		// * 
	3, 		// + 
	2, 		// , 
	3, 		// - 
	1, 		// . 
	3, 		// / 
	3, 		// 0 
	2, 		// 1 
	3, 		// 2 
	3, 		// 3 
	3, 		// 4 
	3, 		// 5 
	3, 		// 6 
	3, 		// 7 
	3, 		// 8 
	3, 		// 9 
	1, 		// : 
	0, 		// ; 
	2, 		// < 
	3, 		// = 
	2, 		// > 
	3, 		// ? 
	0, 		// @ 
	3, 		// A 
	3, 		// B 
	3, 		// C 
	3, 		// D 
	3, 		// E 
	3, 		// F 
	3, 		// G 
	3, 		// H 
	1, 		// I 
	3, 		// J 
	3, 		// K 
	3, 		// L 
	5, 		// M 
	4, 		// N 
	3, 		// O 
	3, 		// P 
	3, 		// Q 
	3, 		// R 
	3, 		// S 
	3, 		// T 
	3, 		// U 
	3, 		// V 
	5, 		// W 
	3, 		// X 
	3, 		// Y 
	3, 		// Z 
	2, 		// ° (mapped to '[')
};

prog_uint16_t Picopixel5_offset[] PROGMEM = 
{
  	0, 		// * 
	3, 		// + 
	6, 		// , 
	8, 		// - 
	11, 		// . 
	12, 		// / 
	15, 		// 0 
	18, 		// 1 
	20, 		// 2 
	23, 		// 3 
	26, 		// 4 
	29, 		// 5 
	32, 		// 6 
	35, 		// 7 
	38, 		// 8 
	41, 		// 9 
	44, 		// : 
	0, 		// ; 
	45, 		// < 
	47, 		// = 
	50, 		// > 
	52, 		// ? 
	0, 		// @ 
	55, 		// A 
	58, 		// B 
	61, 		// C 
	64, 		// D 
	67, 		// E 
	70, 		// F 
	73, 		// G 
	76, 		// H 
	79, 		// I 
	80, 		// J 
	83, 		// K 
	86, 		// L 
	89, 		// M 
	94, 		// N 
	98, 		// O 
	101, 		// P 
	104, 		// Q 
	107, 		// R 
	110, 		// S 
	113, 		// T 
	116, 		// U 
	119, 		// V 
	122, 		// W 
	127, 		// X 
	130, 		// Y 
	133, 		// Z 
	136, 		// ° (mapped to '[')
};

