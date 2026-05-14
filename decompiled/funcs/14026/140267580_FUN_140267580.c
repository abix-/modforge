// Address: 0x140267580
// Ghidra name: FUN_140267580
// ============ 0x140267580 FUN_140267580 (size=260) ============


ulonglong FUN_140267580(undefined1 *param_1,longlong param_2,int param_3,int *param_4)



{

  ushort *puVar1;

  byte bVar2;

  ushort uVar3;

  uint3 uVar4;

  ushort uVar5;

  ulonglong in_RAX;

  

  param_3 = param_3 - *param_4;

  puVar1 = (ushort *)(param_2 + *param_4);

  if (1 < param_3) {

    uVar3 = *puVar1;

    in_RAX = 0;

    if (((int)(uint)uVar3 <= param_3) && (0xe < uVar3)) {

      *param_1 = (char)puVar1[1];

      bVar2 = *(byte *)((longlong)puVar1 + 3);

      *(ushort *)(param_1 + 2) = (ushort)bVar2;

      *(ushort *)(param_1 + 2) = CONCAT11((char)puVar1[2],bVar2);

      bVar2 = *(byte *)((longlong)puVar1 + 5);

      *(ushort *)(param_1 + 4) = (ushort)bVar2;

      *(ushort *)(param_1 + 4) = CONCAT11((char)puVar1[3],bVar2);

      bVar2 = *(byte *)((longlong)puVar1 + 7);

      *(uint *)(param_1 + 8) = (uint)bVar2;

      uVar5 = CONCAT11((char)puVar1[4],bVar2);

      *(uint *)(param_1 + 8) = (uint)uVar5;

      uVar4 = CONCAT12(*(undefined1 *)((longlong)puVar1 + 9),uVar5);

      *(uint *)(param_1 + 8) = (uint)uVar4;

      *(uint *)(param_1 + 8) = CONCAT13((char)puVar1[5],uVar4);

      bVar2 = *(byte *)((longlong)puVar1 + 0xb);

      *(ushort *)(param_1 + 0xc) = (ushort)bVar2;

      *(ushort *)(param_1 + 0xc) = CONCAT11((char)puVar1[6],bVar2);

      bVar2 = *(byte *)((longlong)puVar1 + 0xd);

      *(ushort *)(param_1 + 0xe) = (ushort)bVar2;

      uVar5 = puVar1[7];

      *(ushort *)(param_1 + 0xe) = CONCAT11((byte)uVar5,bVar2);

      *param_4 = *param_4 + (uint)uVar3;

      return CONCAT71((uint7)(byte)uVar5,1);

    }

  }

  return in_RAX & 0xffffffffffffff00;

}




