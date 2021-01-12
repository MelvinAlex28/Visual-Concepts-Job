using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowVRHeadRotation : MonoBehaviour {
    public Transform vrMainObject;
    public float cameraoffsetXZ;
    public float cameraoffsetY;
    public float bodyTurnAngle;

    private Animator myAnim;
    private Vector3 vrRot, myRot;
    private Transform vrCamera;
    private float x, z;


	// Use this for initialization
	void Start () {
        myAnim = GetComponent<Animator>();
        vrCamera = Camera.main.transform;
	}
	
	// Update is called once per frame
	void Update () {
        vrRot = vrCamera.rotation.eulerAngles;
        myRot = transform.rotation.eulerAngles;

        if(Mathf.DeltaAngle(vrRot.y, myRot.y) > bodyTurnAngle)
        {
            if (!gameObject.GetComponent<iTween>())
            {
                Debug.Log("Turn Left");
                myAnim.SetTrigger("TurnOnSpotLeftB");
                iTween.RotateTo(gameObject, new Vector3(myRot.x, vrRot.y, myRot.z), 1f);

            }
        }

        else if (Mathf.DeltaAngle(vrRot.y, myRot.y) < -bodyTurnAngle)
        {
            if (!gameObject.GetComponent<iTween>())
            {
                Debug.Log("Turn Right");
                myAnim.SetTrigger("TurnOnSpotRightB");
                iTween.RotateTo(gameObject, new Vector3(myRot.x, vrRot.y, myRot.z), 1f);

            }
        }
    }

    void LateUpdate()
    {
        x = cameraoffsetXZ * Mathf.Sin(vrCamera.rotation.eulerAngles.y * Mathf.Deg2Rad);
        z = cameraoffsetXZ * Mathf.Cos(vrCamera.rotation.eulerAngles.y * Mathf.Deg2Rad);

        vrMainObject.position = transform.position + new Vector3(x, cameraoffsetY, z);

    }
}
