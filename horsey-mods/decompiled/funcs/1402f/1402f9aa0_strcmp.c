// Address: 0x1402f9aa0
// Ghidra name: strcmp
// ============ 0x1402f9aa0 strcmp (size=103) ============


/* Library Function - Single Match

    strcmp

   

   Libraries: Visual Studio 2012, Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */



int __cdecl strcmp(char *_Str1,char *_Str2)



{

  byte bVar1;

  ulonglong uVar2;

  longlong lVar3;

  

  lVar3 = (longlong)_Str2 - (longlong)_Str1;

  while( true ) {

    if (((ulonglong)_Str1 & 7) == 0) {

      while ((((int)lVar3 + (int)_Str1 & 0xfffU) < 0xff9 &&

             (uVar2 = *(ulonglong *)_Str1, uVar2 == *(ulonglong *)(lVar3 + (longlong)_Str1)))) {

        _Str1 = (char *)((longlong)_Str1 + 8);

        if ((~uVar2 & uVar2 + 0xfefefefefefefeff & 0x8080808080808080) != 0) {

          return 0;

        }

      }

    }

    bVar1 = (byte)*(ulonglong *)_Str1;

    if (bVar1 != *(byte *)(lVar3 + (longlong)_Str1)) break;

    _Str1 = (char *)((longlong)_Str1 + 1);

    if (bVar1 == 0) {

      return 0;

    }

  }

  return -(uint)(bVar1 < *(byte *)(lVar3 + (longlong)_Str1)) | 1;

}




