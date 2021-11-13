#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
	char ra[50] = {0};
	char dec[50] = {0};
	char scale[50] = {0};

	char buffer[100];
	FILE *f = fopen("capt0000.wcs", "r");
	while (fread(buffer, 1, 80, f)) {
		buffer[79] = '\0';
		if (!strncmp(buffer, "CRVAL1", 6)) {
			strncpy(ra, buffer + 17, 13);
		} else if (!strncmp(buffer, "CRVAL2", 6)) {
			strncpy(dec, buffer + 17, 13);
		} else if (!strncmp(buffer, "COMMENT scale", 13)) {
			strncpy(scale, buffer + 15, 17);
		}
	}

	float fra = atof(ra);
	float fdec = atof(dec);
	float fscale = atof(scale);

	puts("Printing some online viewer links:");
	printf("http://worldwidetelescope.org/webclient/#/ra=%f&dec=%f&fov=0.26421\n", fra -  251.568524, fdec);
	printf("https://www.legacysurvey.org/viewer/?ra=%f&dec=%f&layer=unwise-neo6\n", fra, fdec);

	// TODO: figure out rotation
	printf("Upload and view overlay? (y) ");
	if (getchar() == 'y') {
		FILE *f = fopen("upload.sh", "r");
		fgets(buffer, 100, f);
		system(buffer);
		fgets(buffer, 100, f);
		strtok(buffer, "\n");
		printf("http://www.worldwidetelescope.org/wwtweb/ShowImage.aspx?reverseparity=False&scale=%f"
			"&name=capt0000.jpg&imageurl=%s&ra=%f&dec=%f&x=3270.6"
			"&y=1418.4&rotation=144.92&thumb=%s\n", fscale, buffer, fra, fdec, buffer);
	}	
}
