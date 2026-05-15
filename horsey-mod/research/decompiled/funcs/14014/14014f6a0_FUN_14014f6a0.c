// Address: 0x14014f6a0
// Ghidra name: FUN_14014f6a0
// ============ 0x14014f6a0 FUN_14014f6a0 (size=148) ============


undefined8 FUN_14014f6a0(uint *param_1,int *param_2,longlong *param_3,uint *param_4)



{

  undefined8 uVar1;

  uint uVar2;

  

  uVar1 = *(undefined8 *)(param_2 + 2);

  uVar2 = *param_1;

  *(undefined8 *)(param_1 + 0x45) = *(undefined8 *)param_2;

  *(undefined8 *)(param_1 + 0x47) = uVar1;

  if ((uVar2 == 0) || ((uVar2 & 0xf0000000) == 0x10000000)) {

    uVar2 = uVar2 & 0xff;

  }

  else if ((((uVar2 == 0x32595559) || (uVar2 == 0x59565955)) || (uVar2 == 0x55595659)) ||

          (uVar2 == 0x30313050)) {

    uVar2 = 2;

  }

  else {

    uVar2 = 1;

  }

  *param_3 = (longlong)(int)(param_2[1] * param_1[0x44]) + (longlong)(int)(uVar2 * *param_2) +

             *(longlong *)(param_1 + 0x42);

  uVar2 = param_1[0x44];

  *param_4 = uVar2;

  return CONCAT71((uint7)(uint3)(uVar2 >> 8),1);

}




