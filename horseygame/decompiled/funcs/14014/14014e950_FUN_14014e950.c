// Address: 0x14014e950
// Ghidra name: FUN_14014e950
// ============ 0x14014e950 FUN_14014e950 (size=563) ============


undefined8 FUN_14014e950(undefined4 param_1,int *param_2)



{

  char cVar1;

  undefined8 uVar2;

  longlong in_RCX;

  float fVar3;

  float fVar4;

  float fVar5;

  int local_58;

  int local_54;

  int local_50;

  int local_4c;

  undefined1 local_48 [56];

  

  if (param_2 != (int *)0x0) {

    param_1 = 0;

    param_2[0] = 0;

    param_2[1] = 0;

    param_2[2] = 0;

    param_2[3] = 0;

  }

  if ((in_RCX == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,2), cVar1 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    return 0;

  }

  if (*(char *)(in_RCX + 0x2d8) != '\0') {

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    return 0;

  }

  if ((*(longlong *)(in_RCX + 0x1f0) == 0) && (*(longlong *)(in_RCX + 0x118) != 0)) {

    if (param_2 == (int *)0x0) {

      return 1;

    }

    cVar1 = FUN_14016eb20(*(longlong *)(in_RCX + 0x118),&local_58);

    if (cVar1 != '\0') {

      fVar4 = (float)local_58;

      fVar5 = (float)local_54;

      cVar1 = FUN_14014fc50(in_RCX);

      if ((cVar1 != '\0') && (cVar1 = FUN_14014fc50(in_RCX), cVar1 != '\0')) {

        fVar3 = (float)thunk_FUN_1402e33f0(fVar4);

        *param_2 = (int)fVar3;

        fVar3 = (float)thunk_FUN_1402e33f0(fVar5);

        param_2[1] = (int)fVar3;

        fVar4 = (float)thunk_FUN_1402e33f0(((float)local_50 + fVar4) - fVar4);

        param_2[2] = (int)fVar4;

        fVar4 = (float)thunk_FUN_1402e33f0(((float)local_4c + fVar5) - fVar5);

        param_2[3] = (int)fVar4;

        cVar1 = FUN_14014ee70(in_RCX,local_48);

        if (cVar1 != '\0') {

          cVar1 = FUN_140185790(param_2,local_48,param_2);

          if (cVar1 != '\0') {

            return 1;

          }

          uVar2 = FUN_14012e850("No safe area within viewport");

          return uVar2;

        }

      }

    }

    return 0;

  }

  uVar2 = FUN_14014ee70(in_RCX,param_2);

  return uVar2;

}




