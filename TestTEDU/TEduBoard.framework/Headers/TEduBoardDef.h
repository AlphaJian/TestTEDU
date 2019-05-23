//
//  TEduBoardDef.h
//  TEduBoard
//
//  Created by kennethmiao on 2019/4/2.
//  Copyright © 2019年 kennethmiao. All rights reserved.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
typedef UIView TEView;
typedef UIColor TEColor;
#else
#import <AppKit/AppKit.h>
typedef NSView TEView;
typedef NSColor TEColor;
#endif


/**
 * 白板工具类型
 */
typedef NS_ENUM(NSInteger, TEduBoardToolType)
{
    TEDU_BOARD_TOOL_TYPE_MOUSE          = 0,    //鼠标
    TEDU_BOARD_TOOL_TYPE_PEN            = 1,    //画笔
    TEDU_BOARD_TOOL_TYPE_ERASER         = 2,    //橡皮擦
    TEDU_BOARD_TOOL_TYPE_LASER          = 3,    //激光笔
    TEDU_BOARD_TOOL_TYPE_LINE           = 4,    //直线
    TEDU_BOARD_TOOL_TYPE_OVAL           = 5,    //空心椭圆
    TEDU_BOARD_TOOL_TYPE_RECT           = 6,    //空心矩形
    TEDU_BOARD_TOOL_TYPE_OVAL_SOLID     = 7,    //实心椭圆
    TEDU_BOARD_TOOL_TYPE_RECT_SOLID     = 8,    //实心矩形
    TEDU_BOARD_TOOL_TYPE_POINT_SELECT   = 9,    //点选工具
    TEDU_BOARD_TOOL_TYPE_RECT_SELECT    = 10,   //选框工具
    TEDU_BOARD_TOOL_TYPE_TEXT           = 11,   //文本工具
};

/**
 * 白板图片填充对齐模式定义
 * @brief 当以宽度基准等比例放大，则居左和居右同居中对齐效果一致；当以高度基准等比例放大，则居顶和居底同居中对齐效果一致
 */
typedef NS_ENUM(NSInteger, TEduBoardImageFitMode) {
    TEDU_BOARD_IMAGE_FIT_MODE_CENTER        = 0,    //以宽度或者高度为基准居中对齐等比例放大
    TEDU_BOARD_IMAGE_FIT_MODE_LEFT          = 4,    //以宽度或者高度为基准左对齐等比例放大
    TEDU_BOARD_IMAGE_FIT_MODE_TOP           = 5,    //以宽度或者高度为基准顶对齐等比例放大
    TEDU_BOARD_IMAGE_FIT_MODE_RIGHT         = 6,    //以宽度或者高度为基准右对齐等比例放大
    TEDU_BOARD_IMAGE_FIT_MODE_BOTTOM        = 7,    //以宽度或者高度为基准底对齐等比例放大
};

/**
 * 白板图片状态定义
 */
typedef NS_ENUM(NSInteger, TEduBoardImageStatus)
{                                                   //状态描述              对应WEB白板事件
    TEDU_BOARD_IMAGE_STATUS_LOADING         = 1,    //背景图片正在加载        CONSTANT.EVENT.IMG_START_LOAD
    TEDU_BOARD_IMAGE_STATUS_LOAD_DONE       = 2,    //背景图片加载完成        CONSTANT.EVENT.IMG_LOAD
    TEDU_BOARD_IMAGE_STATUS_LOAD_ABORT      = 3,    //背景图片加载中断        CONSTANT.EVENT.IMG_ABORT
    TEDU_BOARD_IMAGE_STATUS_LOAD_ERROR      = 4,    //背景图片加载错误        CONSTANT.EVENT.IMG_ERROR
};

/**
 * 白板文本样式
 */
typedef NS_ENUM(NSInteger, TEduBoardTextStyle)
{
    TEDU_BOARD_TEXT_STYLE_NORMAL            = 0,    //常规样式
    TEDU_BOARD_TEXT_STYLE_BOLD              = 1,    //粗体样式
    TEDU_BOARD_TEXT_STYLE_ITALIC            = 2,    //斜体样式
    TEDU_BOARD_TEXT_STYLE_BOLD_ITALIC       = 3,    //粗斜体样式
};

/**
 * 白板错误码定义（严重）
 */
typedef NS_ENUM(NSInteger, TEduBoardErrorCode)
{                                              //事件说明                     对应WEB白板事件
    TEDU_BOARD_ERROR_INIT           = 1,       //白板加载失败                    无
    TEDU_BOARD_ERROR_AUTH           = 2,       //服务鉴权失败，请先购买服务       CONSTANT.EVENT.VERIFY_SDK_ERROR
    TEDU_BOARD_ERROR_LOAD           = 3,       //白板加载失败                    无
    TEDU_BOARD_ERROR_TIM_INVALID    = 4,       //腾讯云IMSDK不可用               无
};

/**
 * 白板错误码定义（警告）
 */
typedef NS_ENUM(NSInteger, TEduBoardWarningCode)
{
    TEDU_BOARD_WARNING_SYNC_DATA_PARSE_FAILED       = 1,    //接收到其他端的同步数据解析失败
    TEDU_BOARD_WARNING_TIM_SEND_MSG_FAILED          = 2,    //腾讯IMSDK发送消息失败
};

/**
 * 白板上传状态
 */
typedef NS_ENUM(NSInteger, TEduBoardUploadStatus)
{
    TEDU_BOARD_UPLOAD_STATUS_SUCCEED       = 1,    //上传成功
    TEDU_BOARD_UPLOAD_STATUS_FAILED        = 2,    //上传失败
};

/**
 * H5背景状态定义
 */
typedef NS_ENUM(NSInteger, TEduBoardBackgroundH5Status)
{
    TEDU_BOARD_BACKGROUND_H5_STATUS_LOADING       = 1,    //H5背景正在加载
    TEDU_BOARD_BACKGROUND_H5_STATUS_LOAD_FINISH   = 2,    //H5背景加载完成
};


/**
 * 白板信息
 */
@interface TEduBoardInfo : NSObject
//白板ID
@property (nonatomic, strong) NSString *boardId;
//背景图或者背景H5页面的URL
@property (nonatomic, strong) NSString *backgroundUrl;
//白板背景色
@property (nonatomic, strong) TEColor *backgroundColor;
@end


/**
 * 文件信息
 */
@interface TEduBoardFileInfo : NSObject
//文件标识
@property (nonatomic, strong) NSString *fileId;
//文件名称
@property (nonatomic, strong) NSString *title;
//文件下载地址
@property (nonatomic, strong) NSString *downloadURL;
//当前页数
@property (nonatomic, assign) int pageIndex;
//页数
@property (nonatomic, assign) int pageCount;
//白板信息列表
@property (nonatomic, strong) NSArray<TEduBoardInfo *> *boardInfoList;
@end


@interface TEduBoardAuthParam : NSObject
//应用标识
@property (nonatomic, assign) int sdkAppId;
//用户标识
@property (nonatomic, strong) NSString *userId;
//签名
@property (nonatomic, strong) NSString *userSig;
@end

@interface TEduBoardInitParam : NSObject
//默认白板宽高比，可传格式如“4:3”、“16:9”的字符串，默认“16:9”
@property (nonatomic, strong) NSString *ratio;
//是否允许涂鸦，默认YES
@property (nonatomic, assign) BOOL drawEnable;
//全局背景色
@property (nonatomic, strong) TEColor *globalBackgroundColor;
//白板工具，默认TEDU_BOARD_TOOL_TYPE_PEN
@property (nonatomic, assign) TEduBoardToolType toolType;
//画笔颜色
@property (nonatomic, strong) TEColor *brushColor;
//画笔粗细，默认100
@property (nonatomic, assign) int brushThin;
//文本颜色
@property (nonatomic, strong) TEColor *textColor;
//文本粗细，默认320
@property (nonatomic, assign) int textSize;
//文本样式，默认TEDU_BOARD_TEXT_STYLE_NORMAL
@property (nonatomic, assign) TEduBoardTextStyle textStyle;
//文本字体，默认"sans-serif,serif,monospace"
@property (nonatomic, strong) NSString *textFamily;
//是否使用腾讯云IMSDK进行实时数据同步，默认YES
@property (nonatomic, assign) BOOL timSync;
@end



@protocol TEduBoardDelegate <NSObject>
/*************************************************************************************************
 *
 *                                                一、基本流程回调
 *
 *************************************************************************************************/
/**
 * 白板错误回调
 * @param code      错误码，参见TEduBoardErrorCode定义
 * @param msg       错误信息
 */
- (void)onTEBError:(TEduBoardErrorCode)code msg:(NSString *)msg;
/**
 * 白板警告回调
 * @param code      错误码，参见TEduBoardWarningCode定义
 * @param msg       错误信息
 */
- (void)onTEBWarning:(TEduBoardWarningCode)code msg:(NSString *)msg;
/**
 * 白板初始化完成回调，收到该回调后表示白板已处于可正常工作状态
 */
- (void)onTEBInit;
/**
 * 白板历史数据同步完成回调
 */
- (void)onTEBHistroyDataSyncCompleted;
/**
 * 白板同步数据回调
 * @param data      白板同步数据（JSON格式字符串）
 * @brief 收到该回调时需要将回调数据通过信令通道发送给房间内其他人，接受者收到后调用AddSyncData接口将数据添加到白板以实现数据同步,该回调用于多个白板间的数据同步，使用内置IM作为信令通道时，不会收到该回调
 */
- (void)onTEBSyncData:(NSString *)data;
/**
 * 白板可撤销状态改变回调
 * @param canUndo       白板当前是否还能执行Undo操作
 */
- (void)onTEBUndoStatusChanged:(BOOL)canUndo;
/**
 * 白板可重做状态改变回调
 * @param canRedo       白板当前是否还能执行Redo操作
 */
- (void)onTEBRedoStatusChanged:(BOOL)canRedo;


/*************************************************************************************************
 *
 *                                            二、涂鸦相关回调
 *
 *************************************************************************************************/
/**
 * 白板图片状态改变回调
 * @param boardId       白板ID
 * @param url           白板图片URL
 * @param status        新的白板图片状态
 */
- (void)onTEBImageStatusChanged:(NSString *)boardId url:(NSString *)url status:(TEduBoardImageStatus)status;
/**
 * 设置白板背景图片回调
 * @param url           调用setBackgroundImage时传入的url
 * @brief 只有本地调用setBackgroundImage时会收到该回调，收到该回调表示背景图片已经上传或下载成功，并且显示出来
 */
- (void)onTEBSetBackgroundImage:(NSString *)url;
/**
 * 白板图片状态改变回调
 * @param boardId       白板ID
 * @param url           白板图片URL
 * @param status        新的白板图片状态
 */
- (void)onTEBBackgroundH5StatusChanged:(NSString *)boardId url:(NSString *)url status:(TEduBoardBackgroundH5Status)status;
/*************************************************************************************************
 *
 *                                            三、白板页操作回调
 *
 *************************************************************************************************/
/**
 * 增加白板页回调
 * @param boardId       增加的白板页ID
 * @param fileId        增加的白板页所属的文件ID
 */
- (void)onTEBAddBoard:(NSString *)boardId fileId:(NSString *)fileId;
/**
 * 删除白板页回调
 * @param boardId       删除的白板页ID
 * @param fileId        删除的白板页所属的文件ID
 */
- (void)onTEBDeleteBoard:(NSString *)boardId fileId:(NSString *)fileId;
/**
 * 跳转白板页回调
 * @param boardId       跳转到的白板页ID
 * @param fileId        跳转到的白板页所属的文件ID
 */
- (void)onTEBGotoBoard:(NSString *)boardId fileId:(NSString *)fileId;
/*************************************************************************************************
 *
 *                                            四、文件操作回调
 *
 *************************************************************************************************/
/**
 * 增加文件回调
 * @param fileId        增加的文件ID
 * @brief 文件上传完成后才会触发该回调
 */
- (void)onTEBAddFile:(NSString *)fileId;
/**
 * 增加H5动画PPT文件回调
 * @param fileId        增加的文件ID
 * @brief 文件加载完成后才会触发该回调
 */
- (void)onTEBAddH5PPTFile:(NSString *)fileId;
/**
 * 删除文件回调
 * @param fileId        删除的文件ID
 */
- (void)onTEBDeleteFile:(NSString *)fileId;
/**
 * 切换文件回调
 * @param fileId        切换到的文件ID
 */
- (void)onTEBSwitchFile:(NSString *)fileId;
/**
 * 文件上传进度回调
 * @param path              正在上传的文件路径，编码格式为UTF8
 * @param currentBytes      当前已上传大小，单位bytes
 * @param totalBytes        文件总大小，单位bytes
 * @param uploadSpeed       文件上传速度，单位bytes
 */
- (void)onTEBFileUploadProgress:(NSString *)path
                currentBytes:(int)currentBytes
                  totalBytes:(int)totalBytes
                 uploadSpeed:(int)uploadSpeed;
/**
 * 文件上传状态回调
 * @param path              正在上传的文件路径，编码格式为UTF8
 * @param status            文件上传状态
 * @param statusMsg         文件上传状态信息
 */
- (void)onTEBFileUploadStatus:(NSString *)path
                   status:(TEduBoardUploadStatus)status
                    statusMsg:(NSString *)statusMsg;

@end
