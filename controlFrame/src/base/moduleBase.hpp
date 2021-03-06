#pragma once
#include <iostream>
#include <list>
// #include <jsoncpp/json/json.h>
#include "jsoncpp/include/json/json.h"
#include "actionBase.hpp"

class moduleBase
{
  // friend actionBase;

public:
  moduleBase()
  {
    needReply = false;
  }
  virtual ~moduleBase() {}
  virtual void operator()()
  {
    cmdBase = praseCmdtoAction(messageHolder);
    if (cmdBase != nullptr)
    {
      cmdBase->start();
      delete cmdBase;
    }
  };

  virtual actionBase *praseCmdtoAction(Json::Value JsonCmd) = 0;
  // bool MsgToParams(Json::Value, std::vector<autoValue> param); //将消息参数提取出来,格式待定,可以是第一个参数命令号...
  //输出
  Json::Value outPutReply()
  {
    return messageReply;
  }
  //输入
  bool setMessage(Json::Value &msg)
  {
    messageHolder = msg;
    return true;
  };
  bool setReply(Json::Value &data)
  {
    messageReply = data;
    return true;
  }

protected:
  // bool getReply(Json::Value &msg);
  actionBase *cmdBase;
  bool needReply;
  Json::Value messageHolder;
  Json::Value messageReply;
};