// Address: 0x140170a80
// Ghidra name: FUN_140170a80
// ============ 0x140170a80 FUN_140170a80 (size=227) ============


bool FUN_140170a80(longlong param_1,char param_2)



{

  ulonglong uVar1;

  longlong lVar2;

  char cVar3;

  ulonglong uVar4;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return false;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar3 = FUN_1401aa7c0(param_1,1), cVar3 != '\0')))) {

    lVar2 = DAT_1403fc410;

    uVar1 = *(ulonglong *)(param_1 + 0x48);

    if (((param_2 != '\0') != (bool)(~(byte)(uVar1 >> 0x1f) & 1)) &&

       (*(longlong *)(DAT_1403fc410 + 0x180) != 0)) {

      uVar4 = uVar1 & 0xffffffff7fffffff;

      if (param_2 == '\0') {

        uVar4 = uVar1 | 0x80000000;

      }

      *(ulonglong *)(param_1 + 0x48) = uVar4;

      cVar3 = (**(code **)(lVar2 + 0x180))(lVar2,param_1);

      return cVar3 != '\0';

    }

    return true;

  }

  FUN_14012e850("Invalid window");

  return false;

}




