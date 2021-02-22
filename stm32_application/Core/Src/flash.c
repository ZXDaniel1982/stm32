#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

void FLASH_Lock()
{
	SET_BIT(FLASH->CR, FLASH_CR_LOCK);
}

void FLASH_Unlock()
{
	if (READ_BIT(FLASH->CR, FLASH_CR_LOCK) != 0) {
		WRITE_REG(FLASH->KEYR, FLASH_KEY1);
		WRITE_REG(FLASH->KEYR, FLASH_KEY2);
	}
}

bool FLASH_WaitForFinish()
{
	while (FLASH->SR & FLASH_SR_BSY) {
	}

	if (FLASH->SR & FLASH_SR_EOP) {
		FLASH->SR = FLASH_SR_EOP;
	}

	if ((FLASH->SR & FLASH_SR_WRPRTERR) ||
		(FLASH->SR & FLASH_SR_PGERR) || (FLASH->OBR & FLASH_OBR_OPTERR)) {
		return false;
	}
	return true;
}

void FLASH_Erase(uint32_t Add)
{
	if (!FLASH_WaitForFinish()) {
		return;
	}

	SET_BIT(FLASH->CR, FLASH_CR_PER);
	WRITE_REG(FLASH->AR, Add);
	SET_BIT(FLASH->CR, FLASH_CR_STRT);

	while (FLASH->SR & FLASH_SR_BSY) {
	}

	if (!FLASH_WaitForFinish()) {
		return;
	}

	CLEAR_BIT(FLASH->CR, FLASH_CR_PER);
}

bool FLASH_Program(uint8_t * dest, uint8_t * src, uint32_t len)
{
	uint8_t i;
	uint32_t Add;
	uint32_t Data;
	uint32_t index = 0;

	for (index = 0; index < len; index += 4) {
		Add = (uint32_t) (dest + index);
		Data = *(uint32_t *) (src + index);

		if (!FLASH_WaitForFinish()) {
			return false;
		}

		for (i = 0; i < 2; i++) {
			SET_BIT(FLASH->CR, FLASH_CR_PG);
			*(__IO uint16_t *) (Add + 2u * i) = (uint16_t) (Data >> (16u * i));
		}

		if (!FLASH_WaitForFinish()) {
			return false;
		}

		CLEAR_BIT(FLASH->CR, FLASH_CR_PG);

		if (*(uint32_t *) (src) != *(uint32_t *) (dest)) {
			Error_Handle();
			return false;
		}
	}
	return true;
}
