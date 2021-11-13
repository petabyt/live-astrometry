all: usb clean main c

main:
	solve-field --downsample 2 --objs 1000 --crpix-center --no-plots capt0000.jpg

usb:
	rm -rf *.jpg
	gphoto2 --capture-image-and-download
	sleep 1

c:
	tcc -run astro.c

clean:
	rm -rf *.axy *.png *.cr2 *.xyls *.rdls *.solved *.wcs tmp* *.match *.corr *.new
