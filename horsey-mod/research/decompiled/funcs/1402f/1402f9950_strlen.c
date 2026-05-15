// Address: 0x1402f9950
// Ghidra name: strlen
// ============ 0x1402f9950 strlen (size=168) ============


/* Library Function - Single Match

    strlen

   

   Library: Visual Studio */



size_t __cdecl strlen(char *_Str)



{

  ulonglong uVar1;

  ulonglong *puVar2;

  longlong lVar3;

  

  lVar3 = -(longlong)_Str;

  do {

    if (((ulonglong)_Str & 7) == 0) goto LAB_1402f9981;

    uVar1 = *(ulonglong *)_Str;

    _Str = (char *)((longlong)_Str + 1);

  } while ((char)uVar1 != '\0');

LAB_1402f99c8:

  return (size_t)(char *)((longlong)_Str + lVar3 + -1);

LAB_1402f9981:

  do {

    do {

      puVar2 = (ulonglong *)_Str;

      _Str = (char *)(puVar2 + 1);

    } while (((~*puVar2 ^ *puVar2 + 0x7efefefefefefeff) & 0x8101010101010100) == 0);

    uVar1 = *puVar2;

    if ((char)uVar1 == '\0') {

      return (longlong)puVar2 + lVar3;

    }

    if ((char)(uVar1 >> 8) == '\0') {

      return (size_t)(char *)((longlong)puVar2 + lVar3 + 1);

    }

    if ((char)(uVar1 >> 0x10) == '\0') {

      return (size_t)(char *)((longlong)puVar2 + lVar3 + 2);

    }

    if ((char)(uVar1 >> 0x18) == '\0') {

      return (size_t)(char *)((longlong)puVar2 + lVar3 + 3);

    }

    if ((char)(uVar1 >> 0x20) == '\0') {

      return (size_t)(char *)((longlong)puVar2 + lVar3 + 4);

    }

    if ((char)(uVar1 >> 0x28) == '\0') {

      return (size_t)(char *)((longlong)puVar2 + lVar3 + 5);

    }

    if ((char)(uVar1 >> 0x30) == '\0') {

      return (size_t)(char *)((longlong)puVar2 + lVar3 + 6);

    }

  } while ((char)(uVar1 >> 0x38) != '\0');

  goto LAB_1402f99c8;

}




