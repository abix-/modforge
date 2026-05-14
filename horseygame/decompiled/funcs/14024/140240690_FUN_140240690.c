// Address: 0x140240690
// Ghidra name: FUN_140240690
// ============ 0x140240690 FUN_140240690 (size=381) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8

FUN_140240690(longlong param_1,undefined4 param_2,longlong param_3,longlong param_4,

             undefined8 param_5)



{

  code *pcVar1;

  ulonglong uVar2;

  longlong lVar3;

  undefined8 uVar4;

  undefined1 *puVar5;

  uint uVar6;

  int local_res8 [2];

  undefined1 auStack_68 [32];

  longlong local_48;

  longlong local_40;

  undefined8 local_38;

  

  uVar4 = param_5;

  puVar5 = auStack_68;

  local_38 = param_5;

  local_48 = param_3;

  local_40 = param_4;

  (**(code **)(param_1 + 0x50))(param_2,3,&local_48,0);

  (**(code **)(param_1 + 0x10))(param_2);

  (**(code **)(param_1 + 0x38))(param_2,0x8b81,local_res8);

  if (local_res8[0] == 0) {

    (**(code **)(param_1 + 0x38))(param_2,0x8b84,&param_5);

    uVar6 = (int)param_5 + 1;

    if (uVar6 < 0x80) {

      uVar2 = (longlong)(int)uVar6 + 0xf;

      if (uVar2 <= (ulonglong)(longlong)(int)uVar6) {

        uVar2 = 0xffffffffffffff0;

      }

      puVar5 = auStack_68 + -(uVar2 & 0xfffffffffffffff0);

      lVar3 = (longlong)&local_48 + -(uVar2 & 0xfffffffffffffff0);

    }

    else {

      lVar3 = FUN_1401841f0();

    }

    if (lVar3 != 0) {

      pcVar1 = *(code **)(param_1 + 0x30);

      *(undefined8 *)(puVar5 + -8) = 0x140240772;

      (*pcVar1)(param_2,(int)param_5,0,lVar3);

      *(undefined8 *)(puVar5 + -8) = 0x140240783;

      FUN_14012e080(6,"Failed to compile shader:");

      if (param_3 != 0) {

        *(undefined8 *)(puVar5 + -8) = 0x14024079c;

        FUN_14012e080(6,&DAT_14039bf30,param_3);

      }

      if (param_4 != 0) {

        *(undefined8 *)(puVar5 + -8) = 0x1402407b5;

        FUN_14012e080(6,&DAT_14039bf30,param_4);

      }

      *(undefined8 *)(puVar5 + -8) = 0x1402407c9;

      FUN_14012e080(6,&DAT_14039bf30,uVar4);

      *(undefined8 *)(puVar5 + -8) = 0x1402407dd;

      FUN_14012e080(6,&DAT_14039bf30,lVar3);

      if (0x7f < uVar6) {

        *(undefined8 *)(puVar5 + -8) = 0x1402407ed;

        FUN_1401841e0(lVar3);

      }

    }

    uVar4 = 0;

  }

  else {

    uVar4 = 1;

  }

  return uVar4;

}




