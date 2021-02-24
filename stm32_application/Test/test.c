#include <unistd.h>
#include "spc.h"

static uint8_t KeyString[80];
static KeyEnum_t KeyType;

void main()
{
	PageEntity_t *Page = NULL;
	PageEntity_t *PageNext = NULL;

	printf("Spc mainloop task\r\n");
	Page = Page_CreatePage(Default, printf);
	if (Page == NULL) {
		printf("Failed to create page\r\n");
	}
	while (1) {
		/* Block to wait for prvTask1() to notify this task. */
		//sleep(2);
		printf("Please input key: ");
		scanf ("%79s",KeyString);
		KeyType = GetKeyType(KeyString);
		if (Page->func != NULL) {
			PageNext = Page->func(KeyType, printf);
			if (PageNext != NULL) {
				free(Page);
				Page = PageNext;
			}
		} else {
		}
	}
}
