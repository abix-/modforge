// Slim re-implementation of the Dumper-7 SDK's Basic.cpp, *without* pulling in
// Engine_classes.hpp. The original Basic.cpp uses
// UKismetStringLibrary::Conv_StringToName for FName construction, which drags
// in the entire Engine package and (transitively) Engine_functions.cpp -- that
// is what blew up the compile time.
//
// We do not use any function on this DLL that needs StringToName/GetStaticName
// (we look classes up by string via FindClassFast, which doesn't need it). So
// we leave those as stubs that return None.
//
// All other helpers are byte-for-byte the same as the SDK's Basic.cpp.

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>

#include "SDK/Basic.hpp"
#include "SDK/CoreUObject_classes.hpp"
#include "SDK/CoreUObject_structs.hpp"

SDK_NAMESPACE_START

uintptr_t InSDKUtils::GetImageBase()
{
    return reinterpret_cast<uintptr_t>(GetModuleHandle(0));
}

class UClass* BasicFilesImplUtils::FindClassByName(const std::string& Name, bool bByFullName)
{
    return bByFullName ? UObject::FindClass(Name) : UObject::FindClassFast(Name);
}

class UClass* BasicFilesImplUtils::FindClassByFullName(const std::string& Name)
{
    return UObject::FindClass(Name);
}

std::string BasicFilesImplUtils::GetObjectName(class UClass* Class)
{
    return Class->GetName();
}

int32 BasicFilesImplUtils::GetObjectIndex(class UClass* Class)
{
    return Class->Index;
}

uint64 BasicFilesImplUtils::GetObjFNameAsUInt64(class UClass* Class)
{
    return *reinterpret_cast<uint64*>(&Class->Name);
}

class UObject* BasicFilesImplUtils::GetObjectByIndex(int32 Index)
{
    return UObject::GObjects->GetByIndex(Index);
}

UFunction* BasicFilesImplUtils::FindFunctionByFName(const FName* Name)
{
    for (int i = 0; i < UObject::GObjects->Num(); ++i)
    {
        UObject* Object = UObject::GObjects->GetByIndex(i);
        if (!Object) continue;
        if (Object->Name == *Name)
            return static_cast<UFunction*>(Object);
    }
    return nullptr;
}

// We do NOT use StringToName in this DLL. The original SDK impl pulls in
// UKismetStringLibrary, which lives in Engine_classes.hpp. Stub it.
FName BasicFilesImplUtils::StringToName(const wchar_t* /*Name*/)
{
    return FName{};
}

UObject* BasicFilesImplUtils::GetDefaultObjectImpl(UClass* Class)
{
    if (Class)
        return Class->ClassDefaultObject;
    return nullptr;
}

const FName& GetStaticName(const wchar_t* /*Name*/, FName& StaticName)
{
    // No-op: we never call this in our DLL. Returning the (empty) static
    // means STATIC_NAME_IMPL-using sites would misbehave, but we don't use any.
    return StaticName;
}

class UObject* FWeakObjectPtr::Get() const
{
    return UObject::GObjects->GetByIndex(ObjectIndex);
}

class UObject* FWeakObjectPtr::operator->() const
{
    return UObject::GObjects->GetByIndex(ObjectIndex);
}

bool FWeakObjectPtr::operator==(const FWeakObjectPtr& Other) const
{
    return ObjectIndex == Other.ObjectIndex;
}

bool FWeakObjectPtr::operator!=(const FWeakObjectPtr& Other) const
{
    return ObjectIndex != Other.ObjectIndex;
}

bool FWeakObjectPtr::operator==(const class UObject* Other) const
{
    return ObjectIndex == Other->Index;
}

bool FWeakObjectPtr::operator!=(const class UObject* Other) const
{
    return ObjectIndex != Other->Index;
}

SDK_NAMESPACE_END
