// Address: 0x1401c42c0
// Ghidra name: FUN_1401c42c0
// ============ 0x1401c42c0 FUN_1401c42c0 (size=146) ============


undefined8 * FUN_1401c42c0(undefined8 param_1,undefined8 *param_2)



{

  char cVar1;

  undefined8 *puVar2;

  undefined8 local_res8;

  undefined8 local_res10 [3];

  

  cVar1 = FUN_1401c85b0(param_1,param_2[1],*param_2,*(undefined4 *)(param_2 + 3),&local_res8,

                        local_res10);

  if (cVar1 != '\0') {

    puVar2 = (undefined8 *)FUN_1401841a0(1,0x28);

    if (puVar2 != (undefined8 *)0x0) {

      *(undefined4 *)(puVar2 + 2) = *(undefined4 *)((longlong)param_2 + 0x1c);

      *(undefined4 *)((longlong)puVar2 + 0x14) = *(undefined4 *)(param_2 + 4);

      *(undefined4 *)((longlong)puVar2 + 0x1c) = *(undefined4 *)(param_2 + 5);

      *(undefined4 *)(puVar2 + 4) = *(undefined4 *)((longlong)param_2 + 0x24);

      *(undefined4 *)(puVar2 + 3) = *(undefined4 *)((longlong)param_2 + 0x2c);

      *puVar2 = local_res8;

      puVar2[1] = local_res10[0];

      return puVar2;

    }

    FUN_1401841e0(local_res8);

  }

  return (undefined8 *)0x0;

}




