//
//  WBBoardManager.h
//  Whiteboard
//
//  Created by RedRain on 2017/11/6.
//  Copyright © 2017年 RedRain. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WBBoardManager : NSObject

/**
 创建新白板

 @param name 名称
 @param image 封面图片
 */
+ (void)createNewBoardWithName:(NSString *)name
                         image:(UIImage *)image
                  successBlock:(void(^)(void))successBlock
                   failedBlock:(void(^)(NSString *message))failedBlock;



/**
 获取当前用户的所有板子列表
 */
+ (void)boardListForSuccessBlock:(void (^)(NSArray<WBBoardModel *> *boardList))successBlock
                     failedBlock:(void (^)(NSString *message))failedBlock;



/**
 改变当前使用的白板

 @param board 所选中的板子
 */
+ (void)changeUsingBoard:(WBBoardModel *)board
            successBlock:(void(^)(void))successBlock
             failedBlock:(void(^)(NSString *message))failedBlock;



/**
 根据objectID,查询板子的具体信息

 @param objectID 板子的唯一ID
 */
+ (void)boardDetailWithObjectID:(NSString *)objectID
                   successBlock:(void(^)(WBBoardModel *boardModel))successBlock
                    failedBlock:(void(^)(NSString *message))failedBlock;

/**
 板子创建成功,创建板子和用户的关系表
 
 @param boardObj 板子对象
 */
+ (void)createBoardUserMapWithBoardModel:(WBBoardModel *)boardObj
                            successBlock:(void (^)(void))successBlock
                             failedBlock:(void (^)(NSString *message))failedBlock;


#pragma mark - 查询某个用户是否已经加入了某个板子

/**
 查询某个用户是否已经加入了某个板子

 @param boardModel  需要搜索的板子
 */
+ (void)searchCurrentUserJoinBoard:(WBBoardModel *)boardModel
                      successBlock:(void (^)(BOOL isJoin))successBlock
                       failedBlock:(void (^)(NSString *message))failedBlock;
@end
