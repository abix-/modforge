// Address: 0x1401628f0
// Ghidra name: FUN_1401628f0
// ============ 0x1401628f0 FUN_1401628f0 (size=193) ============


void FUN_1401628f0(undefined8 param_1,longlong param_2,uint param_3,char param_4,undefined4 param_5,

                  undefined4 param_6)



{

  undefined8 uVar1;

  char cVar2;

  undefined4 uVar3;

  

  if ((param_2 != 0) && (param_4 == '\0')) {

    uVar1 = FUN_1401611a0();

    uVar3 = FUN_1401611b0(uVar1,param_3,1);

    cVar2 = FUN_140163030(param_2,param_5,param_6,uVar3,param_3 < 0xfffffffe);

    if (cVar2 == '\0') {

      return;

    }

  }

  FUN_140161f10(param_1,param_2,param_3,param_4,param_5,param_6);

  return;

}




