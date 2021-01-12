using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Video;

public class StreamVideo : MonoBehaviour {
    public RawImage rawImage;
    public VideoPlayer videoPlayer;
    public AudioSource audioSource;
    public VideoClip[] videoClips;

    private int videoClipIndex;



	// Use this for initialization
	void Start () {
        StartCoroutine(Playvideo());
	}
	
	IEnumerator Playvideo()
    {
        videoPlayer.Prepare();
        WaitForSeconds WaitForSeconds = new WaitForSeconds(1);
        while (!videoPlayer.isPrepared)
        {
            yield return WaitForSeconds;
            break;
        }
        rawImage.texture = videoPlayer.texture;
        videoPlayer.Play();
        audioSource.Play();

    }

    public void SetNextClip()
    {
        videoClipIndex++;

        if(videoClipIndex >= videoClips.Length)
        {
            videoClipIndex = videoClipIndex % videoClips.Length;
        }

        videoPlayer.clip = videoClips[videoClipIndex];
        videoPlayer.Play();
    }

}
