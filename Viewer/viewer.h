#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QScrollArea>
#include <QToolBar>
#include <QDir>
#include <QClipboard>
#include <QAction>
#include <QFileDialog>
#include <QMenuBar>
#include <QKeyEvent>
#include <QIcon>
#include <QMessageBox>
#include <QLabel>
#include <QSystemTrayIcon>
#include <opencv2/opencv.hpp>
#include "imgWidget.h"
//#include "imageProcess.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

public slots:
    void selectDir();       //选择目录
    void next();            //下一个
    void previous();        //上一个
    void rotateLeft();      //向左旋转
    void rotateRight();     //向右旋转
    void zoomIn();          //放大
    void zoomOut();         //缩小
    void actualSize();      //实际大小
    void fitSize();         //合适大小
    void present();         //显示
    void showAll();         //显示所有栏
    void myClose();         //关闭
	void about();			//关于本软件
	void closeActionUse();  //标签使用关闭
	void openActionUse();   //标签使用开启
	void openCamera();		//打开摄像机
	void controlImage();	//手控图片切换
	void controlImage2();	//手控图片旋转


protected:
    void resizeEvent(QResizeEvent *);       //重定义大小事件
    void keyPressEvent(QKeyEvent *);        //按键事件

private:
    void createActions();                   //创建动作
    void createMenus();                     //创建菜单
    void createToolBars();                  //创建工具条
    void createStatusBar();                 //创建状态栏
	void createTrayIcon();					//创建任务栏图标

	IplImage colorBalance(IplImage* imageBalanced);			//色彩平衡
	IplImage skinColorLikelihood(IplImage* imageLikelihood);//肤色似然
	CvPoint gravity(IplImage* imageLikelihood);				//求重心

    QScrollArea *scrollArea;                //卷轴区域
    ImageWidget *imageWidget;               //图片显示部件

    QMenu *fileMenu;                        //文件操作菜单
    QMenu *editMenu;                        //图片编辑菜单
	QMenu *helpMenu;						//帮助菜单
	QMenu *trayIconMenu;					//任务栏菜单

    QToolBar *fileToolBar;                  //文件操作工具条
    QToolBar *editToolBar;                  //图片编辑工具条

    QAction *dirAct;                        //目录动作
    QAction *nextAct;
    QAction *previousAct;
    QAction *leftAct;
    QAction *rightAct;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *actualSizeAct;
    QAction *fitSizeAct;
    QAction *fullScreenAct;
    QAction *closeAct;
	QAction *aboutAct;

	QAction *openCameraAct;					//OPENCV:打开摄像头
	QAction *imageControlByHandAct;			//手控图片切换
	QAction *imageControlByHandAct2;			//手控图片旋转

	QLabel *statusLabel;					//状态栏标签
	QSystemTrayIcon *trayIcon;

    QStringList imageList;                  //保存图片路径
    int index;                              //图片变量
    QDir imageDir;                          //图片路径
};

#endif // MAINWINDOW_H
