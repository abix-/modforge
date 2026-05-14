// Address: 0x140172440
// Ghidra name: FUN_140172440
// ============ 0x140172440 FUN_140172440 (size=246) ============


undefined8 FUN_140172440(longlong param_1,char *param_2)



{

  char *_Str2;

  code *pcVar1;

  longlong lVar2;

  char cVar3;

  int iVar4;

  undefined8 uVar5;

  char *_Str1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar3 = FUN_1401aa7c0(param_1,1), cVar3 != '\0')))) {

    if ((*(uint *)(param_1 + 0x48) & 0xc0000) != 0) {

      FUN_14012e850("Operation invalid on popup windows");

      return 0;

    }

    _Str2 = *(char **)(param_1 + 8);

    if (param_2 != _Str2) {

      _Str1 = "";

      if (param_2 != (char *)0x0) {

        _Str1 = param_2;

      }

      if ((_Str2 != (char *)0x0) && (iVar4 = strcmp(_Str1,_Str2), iVar4 == 0)) {

        return 1;

      }

      FUN_1401841e0(*(undefined8 *)(param_1 + 8));

      uVar5 = FUN_14012f0d0(_Str1);

      lVar2 = DAT_1403fc410;

      *(undefined8 *)(param_1 + 8) = uVar5;

      pcVar1 = *(code **)(lVar2 + 0x50);

      if (pcVar1 != (code *)0x0) {

        (*pcVar1)(lVar2,param_1);

      }

    }

    return 1;

  }

  FUN_14012e850("Invalid window");

  return 0;

}




