#include "gui_button.h"
#include "gui_label.h"

uint16_t screen[76800] = {0xef7e};

/**
 * Voltage and current sensor handler
 */
static void Term_Fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, const uint16_t *color)
{
	for (uint16_t i=y1;i<=y2;i++) {
		for (uint16_t j=x1;j<=x2;j++) {
			uint16_t index = (uint16_t)240 * i + j;
			screen[index] = *color;
			color++;
		}
	}
}

static void Term_Clean(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
  return;
}

static uint32_t Sim_Tick(void)
{
  return 1;
}

static void Gui_Flush()
{
	for (uint16_t i=0;i<320;i++) {
		for (uint16_t j=0;j<240;j++) {
			uint16_t index = (uint16_t)240 * i + j;
			if (screen[index] == 0xef7e)
				printf(".");
			else if (screen[index] == 0xffff)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
}

void main(void)
{
	memset(screen, 0xef7e, 76800);
	Gui_CreateLabel(Title, 10, 30, (uint8_t *) "wwwwwwwwwwwwwwww", Term_Fill, Term_Clean);
	Gui_CreateLabel(Content, 10, 50, (uint8_t *) "wwwwwwwwwwwwwwww", Term_Fill, Term_Clean);
	Gui_CreateButton(Act, 30, 120, Term_Fill, Sim_Tick);
	Gui_CreateButton(Up, 90, 120, Term_Fill, Sim_Tick);
	Gui_CreateButton(Prog, 150, 120, Term_Fill, Sim_Tick);
	Gui_CreateButton(Left, 30, 170, Term_Fill, Sim_Tick);
	Gui_CreateButton(Enter, 90, 170, Term_Fill, Sim_Tick);
	Gui_CreateButton(Right, 150, 170, Term_Fill, Sim_Tick);
	Gui_CreateButton(Reset, 30, 220, Term_Fill, Sim_Tick);
	Gui_CreateButton(Down, 90, 220, Term_Fill, Sim_Tick);
	Gui_CreateButton(Alarm, 150, 220, Term_Fill, Sim_Tick);

	Gui_UpdateButton();
	Gui_UpdateLabel();
	Gui_Flush();
}
