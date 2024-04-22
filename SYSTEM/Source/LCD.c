// #include "LCD.h"
// /*************************************************************************************************
// *	�� �� ��:	LCD_Test_Clear
// *
// *	��������:	��������
// *************************************************************************************************/
// void LCD_Test_Clear(void)
// {
// 	uint8_t	i = 0;			// ��������
	
// 	LCD_SetDirection(Direction_V);		
// 	LCD_SetTextFont(&CH_Font24);			// ����2424��������,ASCII�����ӦΪ2412
// 	LCD_SetColor(LCD_BLACK);				// ���û�����ɫ

// 	for(i=0;i<8;i++)
// 	{
// 		switch (i)		// �л�����ɫ
// 		{
// 			case 0: LCD_SetBackColor(LIGHT_RED); 		break;	
// 			case 1: LCD_SetBackColor(LIGHT_GREEN); 	break;				
// 			case 2: LCD_SetBackColor(LIGHT_BLUE); 		break;
// 			case 3: LCD_SetBackColor(LIGHT_YELLOW); 	break;
// 			case 4: LCD_SetBackColor(LIGHT_CYAN);		break;
// 			case 5: LCD_SetBackColor(LIGHT_GREY); 		break;
// 			case 6: LCD_SetBackColor(LIGHT_MAGENTA); 	break;
// 			case 7: LCD_SetBackColor(LCD_WHITE); 		break;			
// 			default:	break;			
// 		}
// 		LCD_Clear();		// ����
// 		LCD_DisplayText(13, 70,"STM32 ˢ������");
// 		LCD_DisplayText(13,106,"��Ļ�ֱ���:240*280");
// 		LCD_DisplayText(13,142,"������:ST7789");	
// 		delay_ms(1000);	// ��ʱ
// 	}
// }


// /*************************************************************************************************
// *	�� �� ��:	LCD_Test_Text
// *
// *	��������:	�ı���ʾ����
// *
// *	˵    ��:	��ʾ�ı����������������С�����ĺ�ASCII�ַ� 
// *************************************************************************************************/
// void LCD_Test_Text(void)
// {
// 	LCD_SetBackColor(LCD_BLACK); 			//	���ñ���ɫ
// 	LCD_Clear(); 								// ����
	
// 	LCD_SetColor(LCD_WHITE);
// 	LCD_SetAsciiFont(&ASCII_Font32); LCD_DisplayString(0, 20,"!#$'()*+,-.0123"); 						    		
// 	LCD_SetAsciiFont(&ASCII_Font24); LCD_DisplayString(0, 52,"!#$'()*+,-.012345678"); 				   
// 	LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0, 76,"!#$'()*+,-.0123456789:;<");      	
// 	LCD_SetAsciiFont(&ASCII_Font16); LCD_DisplayString(0, 96,"!#$'()*+,-.0123456789:;<=>?@AB"); 	
// 	LCD_SetAsciiFont(&ASCII_Font12); LCD_DisplayString(0,112,"!#$'()*+,-.0123456789:;<=>?@ABCDEFGHIJKL"); 	
																																		
// 	LCD_SetColor(LCD_CYAN);                                                                             
// 	LCD_SetAsciiFont(&ASCII_Font12); LCD_DisplayString(0,124,"!#&'()*+,-.0123456789:;<=>?@ABCDEFGHIJKL"); 	
// 	LCD_SetAsciiFont(&ASCII_Font16); LCD_DisplayString(0,136,"!#&'()*+,-.0123456789:;<=>?@AB"); 	
// 	LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0,152,"!#&'()*+,-.0123456789:;<");		  	
// 	LCD_SetAsciiFont(&ASCII_Font24); LCD_DisplayString(0,172,"!#&'()*+,-.012345678"); 				  	
// 	LCD_SetAsciiFont(&ASCII_Font32); LCD_DisplayString(0,196,"!#&'()*+,-.0123"); 							  		

// 	LCD_SetTextFont(&CH_Font24);			// ����2424��������,ASCII�����ӦΪ2412
// 	LCD_SetColor(LCD_YELLOW);				// ���û��ʣ���ɫ
// 	LCD_DisplayText(0, 236,"ASCII�ַ���");

// 	delay_ms(2000);	// ��ʱ�ȴ�
// 	LCD_Clear(); 								// ����

// 	LCD_SetTextFont(&CH_Font12);			// ����1212��������,ASCII�����ӦΪ1206
// 	LCD_SetColor(0X8AC6D1);					// ���û���
// 	LCD_DisplayText(14, 30,"1212:���ͿƼ�");	
	
// 	LCD_SetTextFont(&CH_Font16);			// ����1616��������,ASCII�����ӦΪ1608
// 	LCD_SetColor(0XC5E1A5);					// ���û���
// 	LCD_DisplayText(14, 50,"1616:���ͿƼ�");		
	
// 	LCD_SetTextFont(&CH_Font20);			// ����2020��������,ASCII�����ӦΪ2010
// 	LCD_SetColor(0XFFB549);					// ���û���
// 	LCD_DisplayText(14, 80,"2020:���ͿƼ�");		

// 	LCD_SetTextFont(&CH_Font24);			// ����2424��������,ASCII�����ӦΪ2412
// 	LCD_SetColor(0XFF585D);					// ���û���
// 	LCD_DisplayText(14,110,"2424:���ͿƼ�");		

// 	LCD_SetTextFont(&CH_Font32);			// ����3232��������,ASCII�����ӦΪ3216
// 	LCD_SetColor(0xFFB6B9);					// ���û���
// 	LCD_DisplayText(14,150,"3232:���ͿƼ�");		

// 	LCD_SetTextFont(&CH_Font24);			// ����2424��������,ASCII�����ӦΪ2412
// 	LCD_SetColor(LCD_WHITE);
//  	LCD_DisplayText(14,200,"������ʾ");	  

// 	delay_ms(2000);	// ��ʱ�ȴ�
// }
// /************************************************************************************************
// *	�� �� ��:	LCD_Test_Variable
// *
// *	��������:	������ʾ������������С��
// *************************************************************************************************/
// void LCD_Test_Variable (void)
// {
// 	uint16_t i;					// ��������
// 	int32_t	a = 0;			// �����������������ڲ���
// 	int32_t	b = 0;			// �����������������ڲ���
// 	int32_t	c = 0;			// �����������������ڲ���

// 	double p = 3.1415926;	// ���帡�������������ڲ���
// 	double f = -1234.1234;	// ���帡�������������ڲ���
	
// 	LCD_SetBackColor(LCD_BLACK); 			//	���ñ���ɫ
// 	LCD_Clear(); 								// ����
	
//     LCD_SetTextFont(&CH_Font24);     
// 	LCD_SetColor(LIGHT_CYAN);					// ���û��ʣ�����ɫ		
// 	LCD_DisplayText(0,30,"����:");				
// 	LCD_DisplayText(0,60,"����:");					
				
// 	LCD_SetColor(LIGHT_YELLOW);				// ���û��ʣ�����ɫ		
// 	LCD_DisplayText(0,100,"���ո�:");	
// 	LCD_DisplayText(0,130,"���0:");	
	
// 	LCD_SetColor(LIGHT_RED);					// ���û���	������ɫ		
// 	LCD_DisplayText(0,170,"��С��:");	
// 	LCD_DisplayText(0,200,"��С��:");		
	
// 	for(i=0;i<100;i++)
//    {
// 		LCD_SetColor(LIGHT_CYAN);								// ���û���	������ɫ	
// 		LCD_ShowNumMode(Fill_Space);							// ����λ���ո�
// 		LCD_DisplayNumber( 80,30, b+i*10, 4) ;				// ��ʾ����			
// 		LCD_DisplayNumber( 80,60, c-i*10, 4) ;				// ��ʾ����			
		
// 		LCD_SetColor(LIGHT_YELLOW);								// ���û��ʣ�����ɫ	

// 		LCD_ShowNumMode(Fill_Space);								// ����λ��� �ո�
// 		LCD_DisplayNumber( 130,100, a+i*150, 8) ;				// ��ʾ����		

// 		LCD_ShowNumMode(Fill_Zero);								// ����λ���0      
// 		LCD_DisplayNumber( 130,130, b+i*150, 8) ;				// ��ʾ����			
		
// 		LCD_SetColor(LIGHT_RED);									// ���û��ʣ�����ɫ			
// 		LCD_ShowNumMode(Fill_Space);								// ����λ���ո�		
// 		LCD_DisplayDecimals( 100,170, p+i*0.1,  6,3);		// ��ʾС��	
// 		LCD_DisplayDecimals( 100,200, f+i*0.01, 11,4);		// ��ʾС��		
		
// 		delay_ms(15);				
//    }
// 	delay_ms(2500);		
// }
// /*************************************************************************************************
// *	�� �� ��:	LCD_Test_Color
// *
// *	��������:	��ɫ��
// *************************************************************************************************/
// void LCD_Test_Color(void)
// {
// 	uint16_t i;					// ��������
// 	uint16_t y;
// // ��ɫ����>>>>>	
// 	LCD_SetBackColor(LCD_BLACK); //���ñ���ɫ
// 	LCD_Clear(); //������ˢ����ɫ
	
// 	LCD_SetTextFont(&CH_Font20);			// ��������
// 	LCD_SetColor(LCD_WHITE);				// ���û�����ɫ
// 	LCD_DisplayText(0,20,"RGB����ɫ:");

// 	//ʹ�û��ߺ�����������ɫɫ��
// 	for(i=0;i<240;i++)
// 	{
// 		LCD_SetColor( LCD_RED-(i<<16) );
//       LCD_DrawLine_V(0+i,  40,10);
// 	}
// 	for(i=0;i<240;i++)
// 	{
// 		LCD_SetColor( LCD_GREEN-(i<<8) );
//       LCD_DrawLine_V(0+i,  55,10);
// 	}
// 	for(i=0;i<240;i++)
// 	{
// 		LCD_SetColor( LCD_BLUE-i );
//       LCD_DrawLine_V(0+i,  70,10);
// 	}	

//    y = 90;
//    	LCD_SetColor(LIGHT_CYAN);    LCD_FillRect(150,y+5     ,90,10);  LCD_DisplayString(0,y     ,"LIGHT_CYAN");	   
// 	LCD_SetColor(LIGHT_MAGENTA); LCD_FillRect(150,y+20*1+5,90,10);  LCD_DisplayString(0,y+20*1,"LIGHT_MAGENTA");	
// 	LCD_SetColor(LIGHT_YELLOW);  LCD_FillRect(150,y+20*2+5,90,10);  LCD_DisplayString(0,y+20*2,"LIGHT_YELLOW");	
// 	LCD_SetColor(LIGHT_GREY);    LCD_FillRect(150,y+20*3+5,90,10);  LCD_DisplayString(0,y+20*3,"LIGHT_GREY");  	

//    	LCD_SetColor(DARK_CYAN);     LCD_FillRect(150,y+20*4+5,90,10);  LCD_DisplayString(0,y+20*4,"DARK_CYAN");		
// 	LCD_SetColor(DARK_MAGENTA);  LCD_FillRect(150,y+20*5+5,90,10);  LCD_DisplayString(0,y+20*5,"DARK_MAGENTA");	
// 	LCD_SetColor(DARK_YELLOW);   LCD_FillRect(150,y+20*6+5,90,10);  LCD_DisplayString(0,y+20*6,"DARK_YELLOW");	
// 	LCD_SetColor(DARK_GREY);     LCD_FillRect(150,y+20*7+5,90,10);	 LCD_DisplayString(0,y+20*7,"DARK_GREY");	

// 	delay_ms(2000);
// }

// /*************************************************************************************************
// *	�� �� ��:	LCD_Test_Grahic
// *
// *	��������:	2Dͼ�λ���
// *************************************************************************************************/
// void LCD_Test_Grahic(void)
// {
// 	LCD_SetBackColor(LCD_BLACK); //���ñ���ɫ
// 	LCD_Clear(); //������ˢ����ɫ	

// 	LCD_SetColor(LCD_WHITE);	
// 	LCD_DrawRect(0,0,240,280); 			//���ƾ���

// 	LCD_SetColor(LCD_RED);    LCD_FillCircle(140,70,30);		//���Բ��
// 	LCD_SetColor(LCD_GREEN);  LCD_FillCircle(170,70,30); 	
// 	LCD_SetColor(LCD_BLUE);   LCD_FillCircle(200,70,30);  	
	
// 	LCD_SetColor(LCD_YELLOW);
// 	LCD_DrawLine(26,46,113, 84);				//��ֱ��
// 	LCD_DrawLine(35,42,106,101);				//��ֱ��
// 	LCD_DrawLine(45,40, 93,120);				//��ֱ��
// 	LCD_DrawLine(52,36, 69,128);				//��ֱ��
// 	LCD_DrawLine(62,36, 44,128);				//��ֱ��
	
// 	LCD_SetColor(LIGHT_CYAN);
// 	LCD_DrawCircle(120,190,30);			//����Բ��
// 	LCD_DrawCircle(120,190,20);   

// 	LCD_SetColor(LIGHT_RED);	
// 	LCD_DrawEllipse(120,190,90,40); 	//������Բ 
// 	LCD_DrawEllipse(120,190,70,40); 	//������Բ    
// 	LCD_SetColor(LIGHT_MAGENTA);	
// 	LCD_DrawEllipse(120,190,100,50); 	//������Բ
// 	LCD_DrawEllipse(120,190,110,60);  

// 	delay_ms(2000);		
// }
// /*************************************************************************************************
// *	�� �� ��:	LCD_Test_Image
// *
// *	��������:	ͼƬ��ʾ����
// *************************************************************************************************/
// void LCD_Test_Image(void)
// {
// 	LCD_SetBackColor(LCD_BLACK); 			//	���ñ���ɫ
// 	LCD_Clear(); 								// ����
	
// 	LCD_SetColor( 0xffF6E58D);
// 	LCD_DrawImage( 19, 41, 83, 83, Image_Android_83x83) ;	   // ��ʾͼƬ

// 	LCD_SetColor( 0xffDFF9FB);
// 	LCD_DrawImage( 141, 41, 83, 83, Image_Message_83x83) ;	// ��ʾͼƬ
	
// 	LCD_SetColor( 0xff9DD3A8);
// 	LCD_DrawImage( 19, 160, 83, 83, Image_Toys_83x83) ;		// ��ʾͼƬ
	
// 	LCD_SetColor( 0xffFF8753);
// 	LCD_DrawImage( 141, 160, 83, 83, Image_Video_83x83) ;		// ��ʾͼƬ

// 	delay_ms(2000);	
// }
// /*************************************************************************************************
// *	�� �� ��:	LCD_Test_Direction
// *
// *	��������:	������ʾ����
// *************************************************************************************************/
// void  LCD_Test_Direction(void)
// {
// 	int i;
// 	for(i=0;i<4;i++)
// 	{  
//       LCD_SetBackColor(LCD_BLACK); 			//	���ñ���ɫ
//       LCD_Clear(); 								// ����
//       LCD_SetTextFont(&CH_Font24);  
// 	   LCD_SetColor( 0xffDFF9FB);         
// 		switch (i)		// �л�����ɫ
// 		{
// 			case 0:  
//             LCD_SetDirection(Direction_V);		   
//             LCD_DisplayText(20,40,"Direction_V"); 
//          break;	

// 			case 1:  
//             LCD_SetDirection(Direction_H); 	
//             LCD_DisplayText(20,40,"Direction_H"); 
//          break;	

// 			case 2:  
//             LCD_SetDirection(Direction_V_Flip); 
//             LCD_DisplayText(20,40,"Direction_V_Flip"); 
//          break;
// 			case 3: 
//             LCD_SetDirection(Direction_H_Flip); 	
//             LCD_DisplayText(20,40,"Direction_H_Flip"); 
//          break;
	
// 			default:	break;			
// 		}
//       LCD_SetColor( 0xffF6E58D);
//       LCD_DrawImage( 19,100, 83, 83, Image_Android_83x83) ;	   // ��ʾͼƬ
//       LCD_SetTextFont(&CH_Font32);
//       LCD_SetColor( 0xff9DD3A8);  
//       LCD_DisplayText(130,110,"����");
//       LCD_DisplayText(130,150,"�Ƽ�");
 
//       delay_ms(1000);	// ��ʱ
// 	}
// }
