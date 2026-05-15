// Address: 0x1401565b0
// Ghidra name: FUN_1401565b0
// ============ 0x1401565b0 FUN_1401565b0 (size=622) ============


ulonglong FUN_1401565b0(int *param_1,longlong param_2,longlong param_3,int param_4,longlong param_5,

                       int param_6,longlong param_7,int param_8)



{

  longlong lVar1;

  char cVar2;

  ulonglong uVar3;

  char *pcVar4;

  undefined8 in_stack_ffffffffffffff98;

  undefined4 uVar5;

  undefined8 in_stack_ffffffffffffffa0;

  undefined4 uVar6;

  undefined8 in_stack_ffffffffffffffa8;

  undefined4 uVar7;

  undefined8 in_stack_ffffffffffffffb0;

  undefined4 uVar8;

  undefined8 local_38;

  int local_30;

  int local_2c;

  

  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);

  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);

  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);

  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);

  if ((param_1 == (int *)0x0) ||

     ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,3), cVar2 == '\0')))) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","texture");

    return uVar3 & 0xffffffffffffff00;

  }

  if (param_3 == 0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","Yplane");

    return uVar3;

  }

  if (param_4 == 0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","Ypitch");

    return uVar3;

  }

  if (param_5 == 0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","Uplane");

  }

  else if (param_6 == 0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","Upitch");

  }

  else if (param_7 == 0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","Vplane");

  }

  else if (param_8 == 0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","Vpitch");

  }

  else {

    if ((*param_1 == 0x32315659) || (*param_1 == 0x56555949)) {

      local_2c = param_1[2];

      local_38 = 0;

      local_30 = param_1[1];

      if (param_2 != 0) {

        FUN_140185790(param_2,&local_38,&local_38);

      }

      if ((local_30 == 0) || (local_2c == 0)) {

        return CONCAT71((uint7)(uint3)((uint)local_30 >> 8),1);

      }

      if (*(longlong *)(param_1 + 0x40) != 0) {

        uVar3 = FUN_140156250(param_1,&local_38,param_3,param_4,param_5,CONCAT44(uVar6,param_6),

                              param_7,CONCAT44(uVar8,param_8));

        return uVar3;

      }

      lVar1 = *(longlong *)(param_1 + 4);

      if (*(longlong *)(lVar1 + 0x98) != 0) {

        uVar3 = FUN_140149dc0(param_1);

        if ((char)uVar3 == '\0') {

          return uVar3;

        }

        uVar3 = (**(code **)(lVar1 + 0x98))

                          (lVar1,param_1,&local_38,param_3,CONCAT44(uVar5,param_4),param_5,

                           CONCAT44(uVar7,param_6),param_7,param_8);

        return uVar3;

      }

      pcVar4 = "That operation is not supported";

    }

    else {

      pcVar4 = "Texture format must be YV12 or IYUV";

    }

    uVar3 = FUN_14012e850(pcVar4);

  }

  return uVar3;

}




