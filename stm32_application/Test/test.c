#include <unistd.h>
#include "spc.h"

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
		sleep(2);
		if (Page->func != NULL) {
			PageNext = Page->func(printf);
			if (PageNext != NULL) {
				free(Page);
				Page = PageNext;
			}
		} else {
		}
	}
}
