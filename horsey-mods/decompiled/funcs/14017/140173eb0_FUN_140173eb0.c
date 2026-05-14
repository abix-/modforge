// Address: 0x140173eb0
// Ghidra name: FUN_140173eb0
// ============ 0x140173eb0 FUN_140173eb0 (size=325) ============


ulonglong FUN_140173eb0(longlong param_1,longlong param_2,undefined8 param_3,longlong param_4)



{

  char cVar1;

  ulonglong uVar2;

  char *pcVar3;

  

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_1401730c0();

  }

  else {

    if ((param_1 == 0) ||

       ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 == '\0')))) {

      pcVar3 = "Invalid window";

    }

    else {

      if (*(longlong *)(DAT_1403fc410 + 0x210) != 0) {

        if (param_2 == 0) {

          uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","instance");

          return uVar2;

        }

        if (param_4 == 0) {

          uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

          return uVar2;

        }

        uVar2 = *(ulonglong *)(param_1 + 0x48);

        if ((uVar2 >> 0x1c & 1) == 0) {

          if ((uVar2 & 2) != 0) {

            *(ulonglong *)(param_1 + 0x48) = uVar2 & 0xfffffffffffffffd;

            FUN_14016cef0();

          }

          if ((*(ulonglong *)(param_1 + 0x48) >> 0x1d & 1) != 0) {

            *(ulonglong *)(param_1 + 0x48) = *(ulonglong *)(param_1 + 0x48) & 0xffffffffdfffffff;

          }

          cVar1 = FUN_140174130(0);

          if (cVar1 == '\0') {

            uVar2 = FUN_14012e850("failed to load Vulkan library");

            return uVar2;

          }

          *(ulonglong *)(param_1 + 0x48) = *(ulonglong *)(param_1 + 0x48) | 0x10000000;

        }

        uVar2 = (**(code **)(DAT_1403fc410 + 0x210))(DAT_1403fc410,param_1,param_2,param_3,param_4);

        return uVar2;

      }

      pcVar3 = "That operation is not supported";

    }

    uVar2 = FUN_14012e850(pcVar3);

  }

  return uVar2 & 0xffffffffffffff00;

}




