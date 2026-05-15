// Address: 0x140155060
// Ghidra name: FUN_140155060
// ============ 0x140155060 FUN_140155060 (size=144) ============


ulonglong FUN_140155060(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  longlong *plVar1;

  char cVar2;

  ulonglong uVar3;

  

  while ((param_1 != 0 &&

         ((DAT_1403e3d60 == '\0' || (cVar2 = FUN_1401aa7c0(param_1,3), cVar2 != '\0'))))) {

    plVar1 = (longlong *)(param_1 + 0xf8);

    *(undefined4 *)(param_1 + 0x30) = param_2;

    *(undefined4 *)(param_1 + 0x34) = param_3;

    *(undefined4 *)(param_1 + 0x38) = param_4;

    param_1 = *plVar1;

    if (*plVar1 == 0) {

      return 1;

    }

  }

  uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","texture");

  return uVar3 & 0xffffffffffffff00;

}




