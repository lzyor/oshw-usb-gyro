use bevy::prelude::*;
use std::sync::{Arc, Mutex};

use crate::hid::{FilterHidReport, Gyro};

pub fn start_gui() {
    App::new()
        .add_plugins(DefaultPlugins)
        .add_systems(Startup, setup)
        .add_systems(Update, animate)
        .run();
}

#[derive(Component)]
struct MovedPCB;

#[derive(Component)]
struct Dev(Arc<Mutex<Gyro>>);

fn animate(
    moved_pcb: Query<Entity, With<MovedPCB>>,
    mut transforms: Query<&mut Transform>,
    mut dev: Query<&mut Dev, With<MovedPCB>>,
) {
    // read from the device
    let mut report = FilterHidReport::default();
    for d in &mut dev {
        report = d.0.lock().unwrap().read();
        break;
    }
    // map to a rotation
    let v = Vec3::new(
        report.angles[2] / 2.0,
        -report.angles[1] / 2.0,
        report.angles[0] / 2.0,
    );
    for m in &moved_pcb {
        if let Ok(mut transform) = transforms.get_mut(m) {
            *transform = Transform::from_xyz(0.0, 0.0, 0.0);
            transform.rotate_x(v.x);
            transform.rotate_y(v.z);
            transform.rotate_z(-v.y);
        }
    }
}

fn setup(mut commands: Commands, asset_server: Res<AssetServer>) {
    // PCB model
    commands.spawn((Dev(Arc::new(Mutex::new(Gyro::new()))), MovedPCB));
    commands.spawn((
        SceneBundle {
            scene: asset_server.load("models/pcb.gltf#Scene0"),
            ..default()
        },
        MovedPCB,
    ));
    // light
    commands.spawn(PointLightBundle {
        point_light: PointLight {
            shadows_enabled: true,
            ..default()
        },
        transform: Transform::from_xyz(4.0, 8.0, 4.0),
        ..default()
    });
    // camera
    commands.spawn(Camera3dBundle {
        transform: Transform::from_xyz(-2.5, 4.5, 9.0).looking_at(Vec3::ZERO, Vec3::Y),
        ..default()
    });
}
