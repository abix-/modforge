// Address: 0x1401753d0
// Ghidra name: FUN_1401753d0
// ============ 0x1401753d0 FUN_1401753d0 (size=173) ============


ulonglong FUN_1401753d0(undefined4 param_1,undefined8 param_2,longlong param_3,code *param_4,

                       undefined8 param_5)



{

  ulonglong uVar1;

  undefined4 *puVar2;

  

  if (param_3 == 0) {

    if (param_4 != (code *)0x0) {

      (*param_4)(param_5,0);

    }

    uVar1 = FUN_1401745e0(param_1,param_2);

  }

  else {

    puVar2 = (undefined4 *)FUN_1401841a0(1,0x28);

    if (puVar2 == (undefined4 *)0x0) {

      if (param_4 != (code *)0x0) {

        (*param_4)(param_5,param_3);

      }

      uVar1 = FUN_140174970(0,0,0,0);

      uVar1 = uVar1 & 0xffffffffffffff00;

    }

    else {

      *puVar2 = 1;

      *(longlong *)(puVar2 + 2) = param_3;

      *(code **)(puVar2 + 6) = param_4;

      *(undefined8 *)(puVar2 + 8) = param_5;

      uVar1 = FUN_1401750b0(param_1,param_2);

    }

  }

  return uVar1;

}




