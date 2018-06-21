/*
3 binaries (kernel.bin, rootfs.bin, data.bin)
        |
[header] [combined]
  |
[start, length, name| start  ... | start ...]

image.bin
*/

#include<stdio.h>


#define HEADER_OFFSET 84


typedef struct header {
	int start_addr;
	int size;
	char name[20];
} header_t;

int read_file_size (FILE* fd);

int make_image (FILE* kern_fp, FILE * rootfs_fp, FILE * data_fp );

int main () {
		FILE * kernel_fp;
		FILE * rootfs_fp;
		FILE * data_fp;
		FILE * image_fp;
		
		header_t kernel_header, rootfs_header, data_header;
		
		int kernel_sz, rootfs_sz, data_sz;
		kernel_sz= rootfs_sz= data_sz=0;
		
		
		kernel_fp=fopen("kernel.bin","r");
		if (kernel_fp==NULL) {
			return -1;
		}
	
		rootfs_fp=fopen("rootfs.bin","r");
		if (rootfs_fp==NULL) {
			return -1;
		}	


		data_fp=fopen("data.bin","r");
		if (data_fp==NULL) {
			return -1;
		}

	
		kernel_sz=read_file_size(kernel_fp);
			
		if (kernel_sz==0) return -1;
		
		rootfs_sz=read_file_size(rootfs_fp);

		if (rootfs_sz==0) return -1;
		data_sz =read_file_size(data_fp);

		if (data_sz==0)return -1;
		
		
		image_fp=fopen("image.bin","a+");
		
		if (image_fp==NULL) {
			return -1;
		}
		
		kernel_header.start_addr=HEADER_OFFSET;
		kernel_header.size=kernel_sz;
		strcpy(kernel_header.name,"kernel.bin");
		
		fwrite(image_fp, kernel_header, sizeof(kernel_header);
		
		rootfs_header.start_addr=HEADER_OFFSET+kernel_sz;
		rootfs_header.size=rootfs_sz;
		strcpy(rootfs_header.name,"rootfs.bin");
		
		fwrite(image_fp, rootfs_header, sizeof(rootfs_header);
		
		data_header.start_addr=HEADER_OFFSET+kernel_sz+rootfs_sz;
		data_header.size=data_sz;
		strcpy(data_header.name,"data.bin");
		
		fwrite(image_fp, data_header, sizeof(data_header);
	
		fclose(image_fp);
		
		
		make_image(kernel_fp,rootfs_fp,data_fp);
	
				
		fclose (kernel_fp);
		fclose (rootfs_fp);
		fclose (data_fp);
		
	return 0;
}

int read_file_size (FILE *fd) {

	int length=0;
	
	while (fgetc(fd)!=EOF) {
		length++;
	}
	return length;

}


/*
[header] [combined]
  |
[start, length, name| start  ... | start ...]
*/




int make_image (FILE* kern_fp, FILE * rootfs_fp, FILE * data_fp ) {
	
	
	FILE * image_fp;
	header_t  copy_t;
	/* copy the 3 files to image_fp; */
	/* stub code below */
	copy 3 files 
	
	fclose (image_fp);

}
		
		
		
		












