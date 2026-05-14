// Address: 0x140155780
// Ghidra name: FUN_140155780
// ============ 0x140155780 FUN_140155780 (size=522) ============


ulonglong FUN_140155780(int *param_1,longlong param_2,longlong param_3,int param_4,longlong param_5,

                       int param_6)



{

  int iVar1;

  longlong lVar2;

  char cVar3;

  ulonglong uVar4;

  char *pcVar5;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar6;

  undefined8 in_stack_ffffffffffffffc0;

  undefined4 uVar7;

  undefined8 local_28;

  int local_20;

  int local_1c;

  

  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);

  if ((param_1 == (int *)0x0) ||

     ((DAT_1403e3d60 != '\0' && (cVar3 = FUN_1401aa7c0(param_1,3), cVar3 == '\0')))) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","texture");

    return uVar4 & 0xffffffffffffff00;

  }

  if (param_3 == 0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","Yplane");

    return uVar4;

  }

  if (param_4 == 0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","Ypitch");

    return uVar4;

  }

  if (param_5 == 0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","UVplane");

  }

  else if (param_6 == 0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","UVpitch");

  }

  else {

    iVar1 = *param_1;

    if (((iVar1 == 0x3231564e) || (iVar1 == 0x3132564e)) || (iVar1 == 0x30313050)) {

      local_20 = param_1[1];

      local_28 = 0;

      local_1c = param_1[2];

      if (param_2 != 0) {

        FUN_140185790(param_2,&local_28,&local_28);

      }

      if ((local_20 == 0) || (local_1c == 0)) {

        return CONCAT71((uint7)(uint3)((uint)local_1c >> 8),1);

      }

      if (*(longlong *)(param_1 + 0x40) != 0) {

        uVar4 = FUN_140155c50(param_1,&local_28,param_3,param_4,param_5,CONCAT44(uVar7,param_6));

        return uVar4;

      }

      lVar2 = *(longlong *)(param_1 + 4);

      if (*(longlong *)(lVar2 + 0xa0) != 0) {

        uVar4 = FUN_140149dc0(param_1);

        if ((char)uVar4 == '\0') {

          return uVar4;

        }

        uVar4 = (**(code **)(lVar2 + 0xa0))

                          (lVar2,param_1,&local_28,param_3,CONCAT44(uVar6,param_4),param_5,param_6);

        return uVar4;

      }

      pcVar5 = "That operation is not supported";

    }

    else {

      pcVar5 = "Texture format must be NV12, NV21, or P010";

    }

    uVar4 = FUN_14012e850(pcVar5);

  }

  return uVar4;

}




