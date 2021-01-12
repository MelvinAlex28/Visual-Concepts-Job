using System.Collections;
using System.Collections.Generic;
using UnityEngine;


[RequireComponent(typeof(CharacterController))]
public class VRAutowalk : MonoBehaviour {

    //How fast to move
    public float speed = 3.0f;

    //Should I move forward or not
    public bool moveForward;

    //Charactercontroller Script
    private CharacterController controller;

    //VR Main camera
    public Transform vrCamera;


	// Use this for initialization
	void Start () {
        //find the charactercontroller
        controller = GetComponent<CharacterController>();
        //find the VR head
        vrCamera = Camera.main.transform;

	}
	
	// Update is called once per frame
	void Update () {
        //Make sure the player is allowed to move
        //in the google vr button is pressed

        if (Input.GetButtonDown("Fire1"))
        {
            //change the state of moveforward

            moveForward = !moveForward;
           /* if(moveForward == false)
            {
                controller.SimpleMove(Vector3.zero);
            }*/

            //check to see if I should move
            if (moveForward)
            {
                //find the forward direction
                Vector3 forward = vrCamera.TransformDirection(Vector3.forward);
                //tell character controller to move forward

                controller.SimpleMove(forward * speed);
            }
        }
	}
}
