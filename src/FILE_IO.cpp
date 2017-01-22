#include "FILE_IO.h"

size_t readBlock(FILE *fp, char *buffer, int size){
	return fread(buffer, sizeof(char), size, fp);
}

void writeBlock(FILE *fp, char *buffer, int size){
	fwrite(buffer, sizeof(char), size, fp);
}


void RAID0_split(FILE *input, std::vector<FILE*> &out_files){
	char buffer[BLOCK_SIZE];
	int size, index=0;
	printf("%d", input);
	while((size = fread(buffer, sizeof(char), BLOCK_SIZE, input))){
  		fwrite(buffer, sizeof(char), size, out_files[index%out_files.size()]);
		index++;
	}

}


void RAID0_combine(FILE *output, std::vector<FILE*> &in_files){
	char buffer[BLOCK_SIZE];
	int size, index=0;
	while((size = fread(buffer, sizeof(char), BLOCK_SIZE, in_files[index%in_files.size()]))){
		fwrite(buffer, sizeof(char), size, output);
		index++;
	}


}

void RAID1_split(FILE *input, std::vector<FILE> out_files){

}

void RAID5_split(FILE *input, std::vector<FILE> out_files){

}

void combine_file(const char *path, FILE *fp, 
		std::vector<Cloud_Storage_Base_Class*> &cloud_drives,
		std::vector<std::string> &in_files){
	
	std::vector<FILE*> files;
	for(int i = 0; i < in_files.size() ; i++){
		char fpath[256] = "";
		char temp[256];
		sprintf(fpath, "%s/%s", path, in_files[i].c_str());
		printf("%s\n",fpath);
		strcpy(temp,in_files[i].c_str());
		//download file
		cloud_drives[i]->Download(static_config_path, path, temp);
		Decrypt(fpath, "Muffin");
		files.emplace_back(fopen(fpath, "rb"));
	}

	RAID0_combine(fp, files);
	for(auto file : files){
		fclose(file);
	}
}


void split_file(const char *path, const char *manifest, const char *name,
		FILE *fp, std::vector<Cloud_Storage_Base_Class*> &cloud_drives){
	srand(time(NULL));
	char fname[256];
	char fpath[256]= "";
	char fpPath[256] = "";
	char command1[256];
	char command2[256];
	std::vector<FILE*> out_files;
	std::vector<std::string> out_paths;
	std::vector<std::string> file_names;
	for(auto cloud_drive : cloud_drives){
		sprintf(fname, "block%d.rlcs", rand());
		sprintf(fpath, "%s/%s", path, fname);
		file_names.emplace_back(fname);
		out_paths.emplace_back(fpath);
		out_files.emplace_back(fopen(fpath, "w+b"));
	}
	RAID0_split(fp, out_files);
	for(int i = 0; i < out_files.size() ; i++){
		char temp[256];
		fclose(out_files[i]);
		Encrypt(out_paths[i], "Muffin");
		strcpy(temp,out_paths[i].c_str());
		cloud_drives[i]->Upload(static_config_path, temp);
	}

	sprintf(command1, "sed -i \"%s*/d\" %s", name,  manifest);
	sprintf(command2, "echo \"%s 12314 %s %s <key>\" >> %s", 
		 name, file_names[0].c_str(), file_names[1].c_str(), manifest);
	printf("\n%s\n",command1);
	printf("\n%s\n",command2);
	system(command1);
	system(command2);
}
