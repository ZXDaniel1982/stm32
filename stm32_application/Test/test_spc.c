#include <unistd.h>
#include "spc.h"

static uint8_t KeyIn;

static void Demo_Publish(PageInfo_t * info)
{
}

void main()
{
	PageEntity_t *Page = NULL;
	PageEntity_t *PageNext = NULL;

	printf("Spc mainloop task\r\n");
	Page = Page_CreatePage(Default, printf, Demo_Publish);
	if (Page == NULL) {
		printf("Failed to create page\r\n");
	}
	while (1) {
		/* Block to wait for prvTask1() to notify this task. */
		printf("Please input key: ");
		scanf ("%d", (int *)(&KeyIn));
		if (Page->func != NULL) {
			PageNext = Page->func(KeyIn, printf, Page);
			if (PageNext != NULL) {
				free(Page);
				Page = PageNext;
			}
		} else {
		}
	}
}
