# live-astrometry
Live Astrometry Script (Gphoto2 + Astrometry.net)

# Run:
```
tcc -run astro.c
gcc astro.c; ./a.out
```

# Upload and overlay:
Create `upload.sh` with this format:
```
<shell command to upload capt0000.jpg somewhere>
<where to find the resulting image>
```
