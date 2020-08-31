#ifndef QTSERIAL_H
#define QTSERIAL_H

#include <QMainWindow>
#include <QSerialPort>//提供串口访问功能
#include <QSerialPortInfo>//提供系统中存在的串口信息

//#include <wiringPi.h>

QT_BEGIN_NAMESPACE
namespace Ui { class QtSerial; }
QT_END_NAMESPACE

class QtSerial : public QMainWindow
{
    Q_OBJECT

public:
    QtSerial(QWidget *parent = nullptr);
    ~QtSerial();

public:
    bool getSerialPortConfig(void);
    
private slots:

    //重量按钮
    void on_BtWeight_clicked();
    //串口读数据
    void on_SerialPort_readyRead();
    //接收清零
    void on_BtSetZeroRecv_clicked();
    //打开按钮
    void on_BtOpen_clicked();
    //发送按钮
    void on_BtSend_clicked();
    //延时函数，参数为毫秒
    void Sleep(int msec);
    //发送清零
    void on_BtSetZeroSend_clicked();

private:
    Ui::QtSerial *ui;


    bool mBtnStatus;//按钮状态
    bool mIsOpen;//串口状态

    //QSerialPort * mSerialPort = new QSerialPort;

    QSerialPort mSerialPort; //串口实例化
    QString mPortName;//串口名
    QString mBaudRate;//波特率
    QString mParity;//校正位
    QString mDateBits;//数据位
    QString mStopBits;//停止位
    QChar mDataBuf[64];//数据缓存区


};
#endif // QTSERIAL_H
