#include "codec.h"
#include <stdio.h>

int main()
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  google::protobuf::Message* pMsg = createMessage("muduo.Query");
	assert(NULL != pMsg);
	const google::protobuf::Descriptor *pDescriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName("muduo.Query");
	assert(NULL != pDescriptor);
	printf("count id:%d\n",pDescriptor->field_count());
	const google::protobuf::Reflection* pReflection = pMsg->GetReflection();
	assert(NULL != pReflection);
	int i; 
	for(i = 0; i < pDescriptor->field_count(); i++)
	{
			
		const google::protobuf::FieldDescriptor* pFieldDescriptor = pDescriptor->field(i);
		assert(NULL != pFieldDescriptor);
		const std::string& strFieldName = pFieldDescriptor->name();
		printf("[%d]=[%s],%d",i,strFieldName.c_str(),pFieldDescriptor->type());

		printf("%d\n",google::protobuf::FieldDescriptor::TYPE_INT64);
		if (pFieldDescriptor->type() == google::protobuf::FieldDescriptor::TYPE_INT64)
		{
			pReflection->SetInt64(pMsg,pFieldDescriptor,23);
			long long l = pReflection->GetInt64(*pMsg,pFieldDescriptor);
                    	printf("%s = %lld\n",strFieldName.c_str(),l);
		}
		else if(pFieldDescriptor->type() == google::protobuf::FieldDescriptor::TYPE_STRING)
		{
			pReflection->SetString(pMsg,pFieldDescriptor,"OK");
                      	printf("%s = %s\n",strFieldName.c_str(),(pReflection->GetString(*pMsg,pFieldDescriptor)).c_str());

		}
	
	}
	pMsg->Clear();
	delete pMsg;

  puts("");


  google::protobuf::ShutdownProtobufLibrary();
}

