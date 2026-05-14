// Address: 0x1401f0390
// Ghidra name: FUN_1401f0390
// ============ 0x1401f0390 FUN_1401f0390 (size=805) ============


undefined4 * FUN_1401f0390(longlong param_1,int param_2,int param_3)



{

  undefined4 *puVar1;

  undefined *puVar2;

  undefined8 uVar3;

  undefined4 uVar4;

  undefined4 *puVar5;

  int local_res8 [2];

  

  for (puVar5 = *(undefined4 **)(param_1 + 0x248); puVar5 != (undefined4 *)0x0;

      puVar5 = *(undefined4 **)(puVar5 + 0x20)) {

    if ((puVar5[1] == param_2) && (puVar5[2] == param_3)) {

      if (*(undefined4 **)(param_1 + 0x248) == puVar5) {

        return puVar5;

      }

      if (*(longlong *)(puVar5 + 0x20) != 0) {

        *(undefined8 *)(*(longlong *)(puVar5 + 0x20) + 0x78) = *(undefined8 *)(puVar5 + 0x1e);

      }

      if (*(longlong *)(puVar5 + 0x1e) != 0) {

        *(undefined8 *)(*(longlong *)(puVar5 + 0x1e) + 0x80) = *(undefined8 *)(puVar5 + 0x20);

      }

      *(undefined8 *)(puVar5 + 0x1e) = 0;

      *(undefined8 *)(puVar5 + 0x20) = *(undefined8 *)(param_1 + 0x248);

      *(undefined4 **)(*(longlong *)(param_1 + 0x248) + 0x78) = puVar5;

      *(undefined4 **)(param_1 + 0x248) = puVar5;

      return puVar5;

    }

  }

  puVar5 = (undefined4 *)FUN_1401841a0(1,0x88);

  if (puVar5 != (undefined4 *)0x0) {

    puVar5[1] = param_2;

    puVar5[2] = param_3;

    uVar4 = (**(code **)(param_1 + 0x58))();

    *puVar5 = uVar4;

    (**(code **)(param_1 + 0x18))(uVar4,param_2);

    (**(code **)(param_1 + 0x18))(*puVar5,param_3);

    (**(code **)(param_1 + 0x20))(*puVar5,0,"a_position");

    (**(code **)(param_1 + 0x20))(*puVar5,1,"a_color");

    (**(code **)(param_1 + 0x20))(*puVar5,2,"a_texCoord");

    (**(code **)(param_1 + 0xf8))(*puVar5);

    (**(code **)(param_1 + 0xd8))(*puVar5,0x8b82,local_res8);

    if (local_res8[0] != 0) {

      uVar4 = (**(code **)(param_1 + 0xf0))(*puVar5,PTR_s_u_projection_1403e4bf0);

      puVar2 = PTR_s_u_texture_1403e4bf8;

      puVar5[3] = uVar4;

      uVar4 = (**(code **)(param_1 + 0xf0))(*puVar5,puVar2);

      uVar3 = DAT_1403e4c00;

      puVar5[4] = uVar4;

      uVar4 = (**(code **)(param_1 + 0xf0))(*puVar5,uVar3);

      puVar2 = PTR_s_u_texture_v_1403e4c08;

      puVar5[5] = uVar4;

      uVar4 = (**(code **)(param_1 + 0xf0))(*puVar5,puVar2);

      puVar2 = PTR_s_u_palette_1403e4c10;

      puVar5[6] = uVar4;

      uVar4 = (**(code **)(param_1 + 0xf0))(*puVar5,puVar2);

      puVar2 = PTR_s_u_texel_size_1403e4c18;

      puVar5[7] = uVar4;

      uVar4 = (**(code **)(param_1 + 0xf0))(*puVar5,puVar2);

      puVar2 = PTR_s_u_offset_1403e4c20;

      puVar5[8] = uVar4;

      uVar4 = (**(code **)(param_1 + 0xf0))(*puVar5,puVar2);

      puVar2 = PTR_s_u_matrix_1403e4c28;

      puVar5[9] = uVar4;

      uVar4 = (**(code **)(param_1 + 0xf0))(*puVar5,puVar2);

      puVar5[10] = uVar4;

      (**(code **)(param_1 + 0x168))(*puVar5);

      if (puVar5[6] != -1) {

        (**(code **)(param_1 + 0x140))(puVar5[6],2);

      }

      if (puVar5[5] != -1) {

        (**(code **)(param_1 + 0x140))(puVar5[5],1);

      }

      if (puVar5[7] != -1) {

        (**(code **)(param_1 + 0x140))(puVar5[7],1);

      }

      if (puVar5[4] != -1) {

        (**(code **)(param_1 + 0x140))(puVar5[4],0);

      }

      if (puVar5[3] != -1) {

        (**(code **)(param_1 + 0x160))(puVar5[3],1,0,puVar5 + 0xb);

      }

      if (*(longlong *)(param_1 + 0x248) == 0) {

        *(undefined4 **)(param_1 + 0x250) = puVar5;

      }

      else {

        *(longlong *)(puVar5 + 0x20) = *(longlong *)(param_1 + 0x248);

        *(undefined4 **)(*(longlong *)(param_1 + 0x248) + 0x78) = puVar5;

      }

      *(int *)(param_1 + 0x240) = *(int *)(param_1 + 0x240) + 1;

      *(undefined4 **)(param_1 + 0x248) = puVar5;

      if (*(int *)(param_1 + 0x240) < 9) {

        return puVar5;

      }

      puVar1 = *(undefined4 **)(param_1 + 0x250);

      *(undefined8 *)(param_1 + 0x250) = *(undefined8 *)(puVar1 + 0x1e);

      (**(code **)(param_1 + 0x68))(*puVar1);

      FUN_1401841e0(*(undefined8 *)(puVar1 + 0x1c));

      FUN_1401841e0(puVar1);

      *(int *)(param_1 + 0x240) = *(int *)(param_1 + 0x240) + -1;

      return puVar5;

    }

    (**(code **)(param_1 + 0x68))();

    FUN_1401841e0(*(undefined8 *)(puVar5 + 0x1c));

    FUN_1401841e0(puVar5);

    FUN_14012e850("Failed to link shader program");

  }

  return (undefined4 *)0x0;

}




