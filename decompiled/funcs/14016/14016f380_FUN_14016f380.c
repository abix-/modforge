// Address: 0x14016f380
// Ghidra name: FUN_14016f380
// ============ 0x14016f380 FUN_14016f380 (size=223) ============


undefined8 FUN_14016f380(longlong param_1)



{

  ulonglong uVar1;

  char cVar2;

  undefined8 uVar3;

  longlong lVar4;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar2 = FUN_1401aa7c0(param_1,1), cVar2 != '\0')))) {

    if (*(longlong *)(DAT_1403fc410 + 0x228) != 0) {

      uVar1 = *(ulonglong *)(param_1 + 0x48);

      lVar4 = DAT_1403fc410;

      if ((uVar1 >> 0x1d & 1) == 0) {

        if ((uVar1 & 2) != 0) {

          *(ulonglong *)(param_1 + 0x48) = uVar1 & 0xfffffffffffffffd;

          FUN_14016cef0();

        }

        if ((*(ulonglong *)(param_1 + 0x48) >> 0x1c & 1) != 0) {

          *(ulonglong *)(param_1 + 0x48) = *(ulonglong *)(param_1 + 0x48) & 0xffffffffefffffff;

          FUN_1401741d0();

        }

        lVar4 = DAT_1403fc410;

        *(ulonglong *)(param_1 + 0x48) = *(ulonglong *)(param_1 + 0x48) | 0x20000000;

      }

                    /* WARNING: Could not recover jumptable at 0x00014016f448. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar3 = (**(code **)(lVar4 + 0x228))(lVar4,param_1);

      return uVar3;

    }

    FUN_14012e850("That operation is not supported");

    return 0;

  }

  FUN_14012e850("Invalid window");

  return 0;

}




