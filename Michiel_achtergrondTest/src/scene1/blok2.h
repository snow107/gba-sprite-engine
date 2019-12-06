
//{{BLOCK(blok2)

//======================================================================
//
//	blok2, 64x16@8, 
//	+ palette 256 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 512 + 1024 = 1536
//
//	Time-stamp: 2019-11-28, 22:28:59
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BLOK2_H
#define GRIT_BLOK2_H

#define blok2TilesLen 1024
#define blok2PalLen 512


//{{BLOCK(blok2)

//======================================================================
//
//	blok2, 64x16@8,
//	+ palette 256 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 512 + 1024 = 1536
//
//	Time-stamp: 2019-11-28, 22:28:59
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned short blok2Tiles[512] __attribute__((aligned(4)))=
        {
                0x1010,0x1010,0x1010,0x1010,0x1010,0x1010,0x1010,0x1010,
                0x1010,0x1010,0x1010,0x1010,0x1010,0x1010,0x1010,0x1010,
                0x1010,0x1010,0x1010,0x1010,0x1010,0x1010,0x1010,0x1010,
                0x1010,0x1010,0x1010,0x1010,0x1010,0x1010,0x1010,0x1010,
                0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,
                0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,
                0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,
                0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,0x0E0E,

                0x0B0B,0x0000,0x0000,0x0000,0x000B,0x0D0D,0x0D0D,0x0D0D,
                0x0D00,0x0D0D,0x0C0C,0x0C0C,0x0D00,0x0C0C,0x0C0C,0x0C0C,
                0x0D00,0x0C0C,0x0C0C,0x070C,0x0700,0x0C07,0x0C0C,0x0709,
                0x0000,0x0A07,0x080C,0x0007,0x0600,0x0700,0x0707,0x0600,
                0x0000,0x0000,0x0000,0x0000,0x0D0D,0x0D0D,0x0D0D,0x0D0D,
                0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
                0x0707,0x0C0C,0x0C0C,0x070C,0x0700,0x0C07,0x0C0C,0x0707,
                0x0006,0x0707,0x070C,0x0407,0x0606,0x0700,0x0707,0x0601,

                0x0000,0x0000,0x0000,0x0000,0x0D0D,0x0D0D,0x0D0D,0x0D0D,
                0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
                0x0708,0x0C0C,0x0C0C,0x070C,0x0700,0x0C07,0x0C0C,0x0709,
                0x0006,0x0A07,0x080C,0x0007,0x0606,0x0700,0x0707,0x0600,
                0x0000,0x0000,0x0000,0x0000,0x0D0D,0x0D0D,0x0D0D,0x0D0D,
                0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
                0x0707,0x0C0C,0x0C0C,0x070C,0x0700,0x0C07,0x0C0C,0x0707,
                0x0006,0x0707,0x070C,0x0407,0x0606,0x0700,0x0707,0x0601,

                0x0000,0x0000,0x0000,0x0000,0x0D0D,0x0D0D,0x0D0D,0x0D0D,
                0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
                0x0707,0x0C0C,0x0C0C,0x070C,0x0700,0x0C07,0x0C0C,0x0707,
                0x0006,0x0707,0x070C,0x0007,0x0606,0x0700,0x0707,0x0600,
                0x0000,0x0000,0x0000,0x0B0B,0x0D0D,0x0D0D,0x0D0D,0x0B00,
                0x0C0C,0x0C0C,0x0D0D,0x000D,0x0C0C,0x0C0C,0x0C0C,0x000D,
                0x0707,0x0C0C,0x0C0C,0x000D,0x0900,0x0C07,0x0C0C,0x0007,
                0x0006,0x0708,0x070C,0x0007,0x0606,0x0700,0x0707,0x0000,

                0x0E00,0x0E0E,0x0E0E,0x0E0E,0x0E00,0x0E0E,0x0E0E,0x0E0E,
                0x0E00,0x0E0E,0x0E0E,0x0E0E,0x0E00,0x0E0E,0x0E0E,0x0E0E,
                0x0E00,0x0E0E,0x0E0E,0x0E0E,0x0E00,0x0E0E,0x0E0E,0x0E0E,
                0x0E00,0x0E0E,0x0E0E,0x0E0E,0x0E00,0x0E0E,0x0E0E,0x0E0E,
                0x0E0E,0x0E0E,0x0E0E,0x000E,0x0E0E,0x0E0E,0x0E0E,0x000E,
                0x0E0E,0x0E0E,0x0E0E,0x000E,0x0E0E,0x0E0E,0x0E0E,0x000E,
                0x0E0E,0x0E0E,0x0E0E,0x000E,0x0E0E,0x0E0E,0x0E0E,0x000E,
                0x0E0E,0x0E0E,0x0E0E,0x000E,0x0E0E,0x0E0E,0x0E0E,0x000E,

                0x0600,0x0006,0x0007,0x0606,0x0600,0x0606,0x0600,0x0606,
                0x0600,0x0606,0x0606,0x0606,0x0600,0x0606,0x0606,0x0606,
                0x0600,0x0606,0x0606,0x0606,0x0600,0x0606,0x0606,0x0606,
                0x0600,0x0606,0x0606,0x0606,0x0600,0x0606,0x0606,0x0606,
                0x0606,0x0206,0x0307,0x0606,0x0606,0x0606,0x0605,0x0606,
                0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,
                0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,
                0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,

                0x0606,0x0006,0x0007,0x0606,0x0606,0x0606,0x0600,0x0606,
                0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,
                0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,
                0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,
                0x0606,0x0206,0x0307,0x0606,0x0606,0x0606,0x0605,0x0606,
                0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,
                0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,
                0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,

                0x0606,0x0006,0x0007,0x0606,0x0606,0x0606,0x0600,0x0606,
                0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,
                0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,
                0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,
                0x0606,0x0006,0x0007,0x0006,0x0606,0x0606,0x0600,0x0006,
                0x0606,0x0606,0x0606,0x0006,0x0606,0x0606,0x0606,0x0006,
                0x0606,0x0606,0x0606,0x0006,0x0606,0x0606,0x0606,0x0006,
                0x0606,0x0606,0x0606,0x0006,0x0606,0x0606,0x0606,0x0006,
        };

const unsigned short blok2Pal[256] __attribute__((aligned(4)))=
        {
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0400,0x7E66,0x7F66,
                0x7F66,0x7F66,0x7F86,0x7F74,0x7FE6,0x7FF5,0x7021,0x7021,
                0x7473,0x7473,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
        };

//}}BLOCK(blok2)


#endif // GRIT_BLOK2_H

//}}BLOCK(blok2)
