// Address: 0x1401d5930
// Ghidra name: FUN_1401d5930
// ============ 0x1401d5930 FUN_1401d5930 (size=691) ============


ulonglong FUN_1401d5930(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,

                       undefined8 param_6,undefined4 param_7,int param_8,undefined4 param_9,

                       undefined4 param_10,undefined8 param_11,undefined4 param_12)



{

  char cVar1;

  byte bVar2;

  ulonglong uVar3;

  longlong lVar4;

  int iVar5;

  undefined4 local_28 [4];

  

  local_28[0] = 1;

  uVar3 = FUN_1401d4420(param_9,local_28);

  if ((char)uVar3 != '\0') {

    if ((param_3 == 0x16362004) || (param_3 == 0x16161804)) {

      uVar3 = FUN_1401d7800(param_1,param_2,param_6,param_7,param_8,param_11,param_12,local_28[0]);

      return uVar3;

    }

    if (param_8 == 0x30313050) {

      if (param_3 == 0x16572004) {

        uVar3 = FUN_1401d6770(param_1,param_2,param_6,param_7,0x30313050,param_11,param_12,

                              local_28[0]);

        return uVar3;

      }

      iVar5 = param_1 * 4;

      lVar4 = FUN_1401841f0((longlong)iVar5 * (longlong)param_2);

      uVar3 = 0;

      if (lVar4 == 0) goto LAB_1401d5a6f;

      cVar1 = FUN_140144d60(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0x16572004,

                            param_9,param_10,lVar4,iVar5);

      if (cVar1 != '\0') {

        bVar2 = FUN_1401d6770(param_1,param_2,lVar4,iVar5,0x30313050,param_11,param_12,local_28[0]);

        FUN_1401841e0(lVar4);

        return (ulonglong)bVar2;

      }

    }

    else {

      iVar5 = param_1 * 4;

      lVar4 = FUN_1401841f0((longlong)iVar5 * (longlong)param_2);

      uVar3 = 0;

      if (lVar4 == 0) goto LAB_1401d5a6f;

      cVar1 = FUN_140144d60(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0x16161804,

                            0x120005a0,0,lVar4,iVar5);

      if (cVar1 != '\0') {

        bVar2 = FUN_1401d7800(param_1,param_2,lVar4,iVar5,param_8,param_11,param_12,local_28[0]);

        FUN_1401841e0(lVar4);

        return (ulonglong)bVar2;

      }

    }

    uVar3 = FUN_1401841e0(lVar4);

  }

LAB_1401d5a6f:

  return uVar3 & 0xffffffffffffff00;

}




