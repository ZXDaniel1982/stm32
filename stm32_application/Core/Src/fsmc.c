#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

void FSMC_Init()
{
	/* Initialize SRAM control Interface */
	CLEAR_BIT(FSMC_Bank1->BTCR[0], FSMC_BCRx_MBKEN);

	MODIFY_REG(FSMC_Bank1->BTCR[0],
			   (uint32_t) (FSMC_BCRx_FACCEN | FSMC_BCRx_MUXEN | FSMC_BCRx_MTYP |
						   FSMC_BCRx_MWID | FSMC_BCRx_BURSTEN |
						   FSMC_BCRx_WAITPOL | FSMC_BCRx_WRAPMOD |
						   FSMC_BCRx_WAITCFG | FSMC_BCRx_WREN | FSMC_BCRx_WAITEN
						   | FSMC_BCRx_EXTMOD | FSMC_BCRx_ASYNCWAIT |
						   FSMC_BCRx_CBURSTRW),
			   (uint32_t) (FSMC_BCRx_MWID_0 | FSMC_BCRx_WREN));

	/* Initialize SRAM timing Interface */
	MODIFY_REG(FSMC_Bank1->BTCR[1U],
			   (uint32_t) (FSMC_BTRx_ADDSET | FSMC_BTRx_ADDHLD |
						   FSMC_BTRx_DATAST | FSMC_BTRx_BUSTURN |
						   FSMC_BTRx_CLKDIV | FSMC_BTRx_DATLAT |
						   FSMC_BTRx_ACCMOD),
			   (uint32_t) (0x2 | (15 << FSMC_BTRx_ADDHLD_Pos) |
						   (0x5 << FSMC_BTRx_DATAST_Pos) | ((16 - 1U) <<
															FSMC_BTRx_CLKDIV_Pos)
						   | ((17 - 2U) << FSMC_BTRx_DATLAT_Pos)));

	/* Initialize SRAM extended mode timing Interface */
	FSMC_Bank1E->BWTR[0] = 0x0FFFFFFFU;

	/* Enable the NORSRAM device */
	SET_BIT(FSMC_Bank1->BTCR[0], FSMC_BCRx_MBKEN);

	SET_BIT(AFIO->MAPR2, AFIO_MAPR2_FSMC_NADV_REMAP);
}
