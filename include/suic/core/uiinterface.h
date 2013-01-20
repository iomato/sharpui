// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����UIInterface.h
// ��  �ܣ�������Ŀ���û�ע��ӿڡ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIINTERFACE_H_
# define _UIINTERFACE_H_

#include <suic/core/uiconst.h>
#include <suic/framework/uielement.h>
#include <suic/types/uistructure.h>

namespace suic 
{

class __declspec(novtable) IMarkupAttribute : public RefObject
{
public:

    virtual ~IMarkupAttribute() {}

    /// <summary>
    ///     ���ü�¼����һ��
    /// </summary>
    /// <returns>��</returns>
    virtual void Reset() = 0;

    /// <summary>
    ///     �ж��Ƿ񵽼�¼ĩβ
    /// </summary>
    /// <returns>��</returns>
    virtual bool HasNext() = 0;

    /// <summary>
    ///     �ƶ���¼����һ��
    /// </summary>
    /// <returns>��</returns>
    virtual void Next() = 0;

    /// <summary>
    ///     ��ȡ��ǰ��¼ֵ
    /// </summary>
    /// <returns>��ǰ��¼ֵ</returns>
    virtual String Value() = 0;
    virtual String Name() = 0;

    /// <summary>
    ///     ����ָ���ؼ��ֵ�����
    /// </summary>
    /// <param name="key">��������</param>
    /// <returns>����ֵ</returns>
    virtual String Lookup(const String&) = 0;

    /// <summary>
    ///     ȡ�ü�¼����
    /// </summary>
    /// <returns>���Լ�¼����</returns>
    virtual int GetCount() = 0;
};

typedef shared<IMarkupAttribute> MarkupAttributePtr;

class IMarkupNode;
typedef shared<IMarkupNode> MarkupNodePtr;

class __declspec(novtable) IMarkupNode : public RefObject
{
public:

    virtual ~IMarkupNode() {}

    /// <summary>
    ///     ȡ�õ�ǰ�ڵ�ָ��������������ֵ
    /// </summary>
    /// <remarks>
    ///     Ҳ�����Ȼ�ȡ���Լ�����ȡֵ
    /// </remarks>
    /// <param name="key">��������</param>
    /// <returns>����ֵ</returns>
    virtual String Attribute(const String& key) const = 0;

    /// <summary>
    ///     ��ȡ���Լ���
    /// </summary>
    /// <returns>���Լ��϶���</returns>
    virtual MarkupAttributePtr Attributes() = 0;

    /// <summary>
    ///     ��ȡ��ǰ�ڵ�����
    /// </summary>
    /// <returns>�ڵ�����</returns>
    virtual String Name() = 0;

    /// <summary>
    ///     ��ȡ��ǰ�ӽڵ�����
    /// </summary>
    /// <returns>�ӽڵ�����</returns>
    virtual String ChildName() = 0;

    /// <summary>
    ///     ���ü�¼����һ��
    /// </summary>
    /// <returns>��</returns>
    virtual void Reset() = 0;

    /// <summary>
    ///     �ж��Ƿ񵽼�¼ĩβ
    /// </summary>
    /// <returns>true����¼ĩβ</returns>
    virtual bool HasNext() = 0;

    /// <summary>
    ///     �ƶ��ӽڵ㵽��һ��
    /// </summary>
    /// <returns>��</returns>
    virtual void Next() = 0;

    /// <summary>
    ///     ��ȡ��ǰ�ӽڵ����
    /// </summary>
    /// <returns>�ӽڵ����</returns>
    virtual MarkupNodePtr ChildNode() = 0;

    /// <summary>
    ///     ��ȡ��ǰ�ӽڵ����
    /// </summary>
    /// <returns>�ӽڵ����</returns>
    virtual int GetCount() = 0;
};

enum eBuildType { eNone, eApplication, eElement, eResourceDic, eResourceMerge, eResource, eStyle, eProperty };

typedef delegate<ElementPtr()> BuildListener;
typedef delegate<ObjectPtr(const String&, IMarkupNode*, eBuildType)> ElementBuilder;
typedef delegate<ObjectPtr(const String&, const String&)> AttributeReader;
typedef delegate<bool(ObjectPtr,MessageParameter)> MessageListener;
typedef delegate<ObjectPtr(ObjectPtr)> ContentBuilder;

class __declspec(novtable) IInitializeHook : public RefObject
{
public:

    virtual ~IInitializeHook() {}

    virtual void OnStart(ElementPtr root, ObjectPtr&) = 0;
    virtual void OnEnd(ElementPtr root, ObjectPtr&) = 0;
    virtual void OnError(const String& error) = 0;
};

typedef shared<IInitializeHook> InitializeHookPtr;
typedef delegate<void(int)> TimerFunc;

struct AnimateItem
{
    ImagePtr img;

    int elapse;
    int transparent;
    int x;
    int y;
    int w;
    int h;
    int flag;
};

struct GifDescriptor
{
    unsigned short w;
    unsigned short h;

    unsigned char packed;
    unsigned char bkIndex;
    unsigned char pixelAspect;

    Color bkcolor;
};

}

# endif