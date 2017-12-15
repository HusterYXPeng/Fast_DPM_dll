#include "FastDPM.h"
#include <conio.h>
using namespace std;
vector<string>  yuStdDirFiles( string DirName, vector<string> FileExtensions );
string trim_file_name( string FileName, int FLAG );

extern "C" int __declspec(dllexport) DpmDll(string img_dir, string ModelPath, string path_result);
int DpmDll(string img_dir, string ModelPath, string path_result)
{
	//return 1;

	cout << "start the detection by DPM" << endl;
	
	// 设置放置图像的文件夹
	//img_dir = "D:\\2017   labview 中文版本\\自己弄的\\Source cpp Files\\FastDPM-2015-Nov\\FastDPM-2014-May\\photo_src\\第一步处理";
	string extensions[] = { ".jpg" };
	vector<string>	img_extensions(extensions, extensions + 1);
	vector<string>	imgnames = yuStdDirFiles(img_dir, img_extensions);

	//加载模型
	//string ModelPath = "D:/2017   labview 中文版本/自己弄的/Source cpp Files/FastDPM-2015-Nov/FastDPM-2014-May/model_inriaperson.txt";
	FastDPM	PM(ModelPath);//行人检测
	//FastDPM	PM("car_final.txt");//车辆检测
	//FastDPM	PM("model.txt");
	

	// 开始检测
	bool flag = false;
	for(unsigned i=0; i<imgnames.size(); i++ )
	{
		Mat	img_uint8 = imread(imgnames[i]);
		if (img_uint8.empty()){
			cout << "Cannot get image " << imgnames[i] << endl;
			getchar();
			return -2;
		        }
		Mat	img = PM.prepareImg( img_uint8 );
		PM.detect( img, -1.0f, true, true, path_result+"\\"+to_string(i)+".jpg");	
		if( PM.detections.empty())
			continue;
		flag = true;  
		char key = waitKey(5000);
		if (key == 27)
			break;
		cout << "完成检测了一张图" << endl;
	}
	cout << "Finished!" << endl;
	if (flag)
		waitKey();
	else
		_getch();
	return 1;
}



// 测试dll
int main()
{
	//return DpmDll("img", "model_inriaperson.txt");
}







