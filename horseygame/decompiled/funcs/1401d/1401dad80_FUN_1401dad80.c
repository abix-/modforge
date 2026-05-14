// Address: 0x1401dad80
// Ghidra name: FUN_1401dad80
// ============ 0x1401dad80 FUN_1401dad80 (size=963) ============


undefined1

FUN_1401dad80(ulonglong param_1,int param_2,ulonglong param_3,undefined4 param_4,undefined4 param_5,

             undefined8 param_6,undefined4 param_7,int param_8,undefined4 param_9,

             undefined4 param_10,ulonglong param_11,undefined4 param_12)



{

  int iVar1;

  char cVar2;

  undefined1 uVar3;

  longlong lVar4;

  undefined8 uVar5;

  undefined8 uVar6;

  undefined8 uVar7;

  undefined8 *puVar8;

  undefined4 uVar9;

  undefined4 uVar10;

  undefined4 *puVar11;

  undefined4 uVar12;

  undefined4 uVar13;

  undefined4 uVar16;

  undefined8 uVar14;

  ulonglong uVar15;

  undefined8 in_stack_ffffffffffffff98;

  undefined4 local_58;

  undefined4 local_54;

  undefined4 local_50 [2];

  undefined8 local_48;

  undefined8 local_40;

  undefined8 local_38 [2];

  

  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);

  local_38[0] = 0;

  local_40 = 0;

  local_48 = 0;

  local_54 = 0;

  local_58 = 0;

  puVar11 = &local_54;

  puVar8 = &local_48;

  local_50[0] = 1;

  cVar2 = FUN_1401d4490(param_1,param_2,param_3,param_6,param_7,local_38,&local_40,puVar8,puVar11,

                        &local_58);

  uVar10 = (undefined4)((ulonglong)puVar8 >> 0x20);

  uVar13 = (undefined4)((ulonglong)puVar11 >> 0x20);

  if (cVar2 == '\0') {

    return 0;

  }

  cVar2 = FUN_1401d4420(param_4,local_50);

  uVar12 = local_50[0];

  if (cVar2 == '\0') {

    return 0;

  }

  uVar7 = CONCAT44(uVar13,local_58);

  uVar6 = CONCAT44(uVar10,local_54);

  cVar2 = FUN_1401dba20(param_3 & 0xffffffff,param_8,param_1 & 0xffffffff,param_2,local_38[0],

                        local_40,local_48,uVar6,uVar7,param_11,CONCAT44(uVar9,param_12),local_50[0])

  ;

  if (cVar2 != '\0') {

    return 1;

  }

  uVar7 = CONCAT44((int)((ulonglong)uVar7 >> 0x20),local_58);

  uVar6 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),local_54);

  cVar2 = FUN_14000c9a0(param_3 & 0xffffffff,param_8,param_1 & 0xffffffff,param_2,local_38[0],

                        local_40,local_48,uVar6,uVar7,param_11,param_12,uVar12);

  if (cVar2 != '\0') {

    return 1;

  }

  uVar12 = (undefined4)((ulonglong)uVar7 >> 0x20);

  uVar9 = (undefined4)((ulonglong)uVar6 >> 0x20);

  uVar6 = local_38[0];

  uVar7 = local_48;

  uVar15 = param_11;

  cVar2 = FUN_1401dc0d0();

  uVar10 = (undefined4)((ulonglong)uVar6 >> 0x20);

  uVar13 = (undefined4)((ulonglong)uVar7 >> 0x20);

  uVar16 = (undefined4)(uVar15 >> 0x20);

  if (cVar2 != '\0') {

    return 1;

  }

  iVar1 = (int)param_1;

  if ((int)param_3 == 0x30313050) {

    if (param_8 != 0x16572004) {

      lVar4 = FUN_1401841f0((longlong)(iVar1 * 4) * (longlong)param_2);

      if (lVar4 == 0) {

        return 0;

      }

      uVar14 = CONCAT44(uVar16,param_5);

      uVar7 = CONCAT44(uVar12,param_4);

      uVar6 = CONCAT44(uVar9,0x16572004);

      cVar2 = FUN_1401dad80(param_1 & 0xffffffff,param_2,0x30313050,param_4,CONCAT44(uVar10,param_5)

                            ,param_6,CONCAT44(uVar13,param_7),uVar6,uVar7,uVar14,lVar4,iVar1 * 4);

      if (cVar2 != '\0') {

        uVar5 = 0x16572004;

        uVar9 = (undefined4)((ulonglong)uVar14 >> 0x20);

        uVar13 = (undefined4)((ulonglong)uVar7 >> 0x20);

        uVar10 = (undefined4)((ulonglong)uVar6 >> 0x20);

        goto LAB_1401db03b;

      }

      goto LAB_1401dafcc;

    }

  }

  else if (param_8 == 0x16362004) {

    uVar3 = FUN_14012e850("Unsupported YUV conversion");

    return uVar3;

  }

  lVar4 = FUN_1401841f0((longlong)(iVar1 * 4) * (longlong)param_2);

  if (lVar4 == 0) {

    return 0;

  }

  uVar15 = uVar15 & 0xffffffff00000000;

  uVar7 = CONCAT44(uVar12,0x120005a0);

  uVar6 = CONCAT44(uVar9,0x16362004);

  cVar2 = FUN_1401dad80(param_1 & 0xffffffff,param_2,param_3 & 0xffffffff,param_4,

                        CONCAT44(uVar10,param_5),param_6,CONCAT44(uVar13,param_7),uVar6,uVar7,uVar15

                        ,lVar4,iVar1 * 4);

  if (cVar2 != '\0') {

    param_4 = 0x120005a0;

    uVar5 = 0x16362004;

    uVar9 = (undefined4)(uVar15 >> 0x20);

    uVar13 = (undefined4)((ulonglong)uVar7 >> 0x20);

    uVar10 = (undefined4)((ulonglong)uVar6 >> 0x20);

    param_5 = 0;

LAB_1401db03b:

    uVar3 = FUN_140144d60(param_1 & 0xffffffff,param_2,uVar5,param_4,param_5,lVar4,iVar1 * 4,

                          CONCAT44(uVar10,param_8),CONCAT44(uVar13,param_9),CONCAT44(uVar9,param_10)

                          ,param_11,param_12);

    FUN_1401841e0(lVar4);

    return uVar3;

  }

LAB_1401dafcc:

  FUN_1401841e0(lVar4);

  return 0;

}




