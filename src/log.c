#include "../include/log.h"

void _ced_log(FILE *file, const char *fmt, ...){
	va_list ap;
	time_t t;
	char datestr[51]; //fixed format date
	
	file = (file == NULL) ? stderr : file;

	t = time(NULL);
	tzset();
	strftime(datestr, sizeof(datestr) - 1, "%a %b %d %T %Z %Y", localtime(&t));
	fprintf(file, "%s [%d]: ",datestr, getpid());

	va_start(ap, fmt);
	vfprintf(file, fmt, ap);
	va_end(ap);

	fprintf(file, "\n");

}
